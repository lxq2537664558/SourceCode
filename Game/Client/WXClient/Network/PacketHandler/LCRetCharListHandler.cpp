#include "StdAfx.h"
#include "LCRetCharList.h"
#include "CLAskCharLogin.h"
#include "CLAskCreateChar.h"
#include "CLAskDeleteChar.h"
#include "gamestruct.h"
#include "..\..\event\GMEventSystem.h"
#include "..\..\procedure\GamePro_CharSel.h"
#include "..\..\procedure\GamePro_CharCreate.h"

UINT	LCRetCharListHandler::Execute(LCRetCharList* pPacket, Player* pPlayer )
{
	__ENTER_FUNCTION

		if(pPacket&&(pPacket->GetResult() == ASKCHARLIST_SUCCESS))
		{

			int iCharacterCount = pPacket->GetCharNumber();
			// �����ɫ�ĸ���
			CGameProcedure::s_pProcCharSel->m_iCharacterCount = 0;

			if( iCharacterCount > 0)
			{
				DB_CHAR_BASE_INFO* pInfo = NULL;
				for(int i = 0; i < iCharacterCount; i++)
				{
					pInfo = pPacket->GetCharBaseInfo(i);
					if(pInfo)
					{
						// ����һ����ɫ
						CGameProcedure::s_pProcCharSel->AddCharacter(*pInfo);
				
						CGameProcedure::s_pProcCharCreate->m_iCamp = pInfo->m_Camp;
					}

				}
				
			}
			else
			{
				CGameProcedure::s_pProcCharCreate->m_iCamp = -1;
			}

			CGameProcedure::s_pEventSystem->PushEvent( GE_GAMELOGIN_CLOSE_SYSTEM_INFO);	


			// ת��������ѡ����档
			if(CGameProcedure::GetActiveProcedure() == (CGameProcedure*)CGameProcedure::s_pProcCharCreate)
			{
				if(CGameProcedure::s_pProcCharCreate->m_Status == CGamePro_CharCreate::CHAR_CREATE_CREATE_OK)
				{
					CGameProcedure::s_pProcCharCreate->ChangeToRoleSel();
				}
			}

			
		}
		else
		{
			ASKCHARLIST_RESULT ListResult;
			ListResult = pPacket->GetResult();
		
			switch(ListResult)
			{
			case ASKCHARLIST_OP_FAILS://����ʧ��
				{
					CGameProcedure::s_pEventSystem->PushEvent( GE_GAMELOGIN_SHOW_SYSTEM_INFO, "�õ���ɫ��Ϣ����! ");	
					break;
				}
			case ASKCHARLIST_SERVER_BUSY://������æ������
				{
					CGameProcedure::s_pEventSystem->PushEvent( GE_GAMELOGIN_SHOW_SYSTEM_INFO, "�õ���ɫ��Ϣ����! ��������æ.");	
					break;
				}
			case ASKCHARLIST_OP_TIMES://��������Ƶ��
				{
					CGameProcedure::s_pEventSystem->PushEvent( GE_GAMELOGIN_SHOW_SYSTEM_INFO, "�õ���ɫ��Ϣ����! ��������Ƶ��.");	
					break;
				}
			default:
				{
					CGameProcedure::s_pEventSystem->PushEvent( GE_GAMELOGIN_SHOW_SYSTEM_INFO, "δ֪����!");	
					break;
				}
			}
					
		}

		CGameProcedure::s_pEventSystem->PushEvent( GE_GAMELOGIN_REFRESH_ROLE_SELECT_CHARACTOR);
		return PACKET_EXE_CONTINUE;

	__LEAVE_FUNCTION

		return PACKET_EXE_ERROR;
}