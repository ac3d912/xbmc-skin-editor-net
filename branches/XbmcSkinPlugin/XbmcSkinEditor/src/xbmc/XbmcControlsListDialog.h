/*
This file is part of Xbmc skin editor for notepad++
Copyright (C) 2012 Ti-BEN

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef XBMC_CONTROLS_LIST_DIALOG_H
#define XBMC_CONTROLS_LIST_DIALOG_H


#include "ModelViewController.h"
#include "DockingDlgInterface.h"
#include "ClipboardControls/MultiClipboardListbox.h"

// ID for dockable window
#define  MULTICLIPBOARD_DOCKABLE_WINDOW_INDEX 0


class CXbmcControlsListDialog : public DockingDlgInterface, public IController
{
public:
  CXbmcControlsListDialog();
  ~CXbmcControlsListDialog();
  // Not inherited from DockingDlgInterface
  virtual void Init( IModel * pNewModel, MultiClipboardProxy * pClipboardProxy, LoonySettingsManager * pSettings );
  virtual void Shutdown();
  // Inherited from DockingDlgInterface
  virtual void destroy() {}

  void ShowDialog( bool Show = TRUE );

  virtual void OnModelModified();
  void SetHidden() { IsShown = false; }
  bool IsShowed() { return IsShown; }
  
protected:
  // Overload DockingDlgInterface's dialog procedure
  virtual BOOL CALLBACK run_dlgProc( HWND hWnd, UINT msg, WPARAM wp, LPARAM lp );

  // Initialise dialog here
  void InitialiseDialog();
  // Toolbar commands
  void tb_cmd(UINT message);
private:
  tTbData TBData;
  bool IsShown;
  MultiClipboardListbox m_pListBox;
  void ShowXbmcControls();
  void OnListSelectionChanged();

  virtual void OnObserverAdded( LoonySettingsManager * SettingsManager );
  virtual void OnSettingsChanged( const stringType & GroupName, const stringType & SettingName );
};


#endif