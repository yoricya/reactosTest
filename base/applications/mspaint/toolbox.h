/*
 * PROJECT:     PAINT for ReactOS
 * LICENSE:     LGPL
 * FILE:        base/applications/mspaint/toolbox.h
 * PURPOSE:     Window procedure of the main window and all children apart from
 *              hPalWin, hToolSettings and hSelection
 * PROGRAMMERS: Benedikt Freisen
 */

#pragma once

#define TOOLBAR_ROWS        8
#define TOOLBAR_COLUMNS     2
#define CXY_TB_BUTTON       25
#define CX_TOOLBAR          (TOOLBAR_COLUMNS * CXY_TB_BUTTON)
#define CY_TOOLBAR          (TOOLBAR_ROWS * CXY_TB_BUTTON)

class CToolBox : public CWindowImpl<CToolBox>
{
public:
    DECLARE_WND_CLASS_EX(_T("ToolBox"), CS_DBLCLKS, COLOR_BTNFACE)

    BEGIN_MSG_MAP(CToolBox)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_SYSCOLORCHANGE, OnSysColorChange)
        MESSAGE_HANDLER(WM_COMMAND, OnCommand)
        MESSAGE_HANDLER(WM_TOOLSMODELTOOLCHANGED, OnToolsModelToolChanged)
    END_MSG_MAP()

    BOOL DoCreate(HWND hwndParent);

private:
    CWindow toolbar;

    LRESULT OnCreate(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnSysColorChange(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnCommand(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnToolsModelToolChanged(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
};
