// WindowEventLog.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <Windows.h>


#define BUFFER_SIZE	(1024 * 64)
LPCTSTR pEventTypeNames[] = {_T("Application"), _T("System"), _T("CurrentControlSet"), _T("Services"), _T("EventLog"), _T("Application"), _T("Security"), _T("WinApp"), NULL };


int _tmain(int argc, _TCHAR* argv[])
{
	// [2017-7-18 swkim] window event를 연다.
	BYTE bBuffer[BUFFER_SIZE] = {0};
	DWORD dwRead, dwNeeded, dwThisRecord, dwNumOfRecord;

	HANDLE hEventLog = OpenEventLog(NULL, _T("Application"));

	if( hEventLog )
	{
		PEVENTLOGRECORD pEvent = (PEVENTLOGRECORD)&bBuffer;

		GetOldestEventLogRecord(hEventLog, &dwThisRecord);
		GetNumberOfEventLogRecords(hEventLog, &dwNumOfRecord);

		while ( ReadEventLog(hEventLog, EVENTLOG_FORWARDS_READ | EVENTLOG_SEQUENTIAL_READ, 0, pEvent, BUFFER_SIZE, &dwRead, &dwNeeded))
		{
			while(dwRead > 0)
			{
				printf(_T("%03d EVENT ID : 0x%08X Event Type : "), dwThisRecord++, pEvent->EventID);

				switch(pEvent->EventType)
				{
				
				case EVENTLOG_ERROR_TYPE :
					{
						printf("EVENTLOG_ERROR_TYPE\n");
					}break;
				case EVENTLOG_WARNING_TYPE:
					{
						printf("EVENTLOG_WARNING_TYPE\n");

					}break;
				case EVENTLOG_INFORMATION_TYPE:
					{
						printf("EVENTLOG_INFORMATION_TYPE\n");

					}break;
				case EVENTLOG_AUDIT_SUCCESS:
					{
						printf("EVENTLOG_AUDIT_SUCCESS\n");

					}break;
				case EVENTLOG_AUDIT_FAILURE:
					{
						printf("EVENTLOG_AUDIT_FAILURE\n");
						
					}break;
				default:
					{
						printf("unknown\n");
					}
				}
				printf(_T("EVENT source %s\n"), (LPSTR)(LPBYTE)pEvent + sizeof(EVENTLOGRECORD));

				// [2017-7-18 swkim] Getstring



				dwRead -= pEvent->Length;
				pEvent = (PEVENTLOGRECORD) ((LPBYTE)pEvent + pEvent->Length);
			}

			pEvent = (PEVENTLOGRECORD)&bBuffer;
		}

		CloseEventLog(hEventLog);
	}

	system(_T("pause"));
	
	return 0;
}