// Copyright 2017 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#include "DolphinNode/Config/ControllersWindow.h"

#include <QDialogButtonBox>
#include <QVBoxLayout>

#include "DolphinNode/Config/CommonControllersWidget.h"
#include "DolphinNode/Config/GamecubeControllersWidget.h"
#include "DolphinNode/Config/WiimoteControllersWidget.h"
#include "DolphinNode/QtUtils/WrapInScrollArea.h"

ControllersWindow::ControllersWindow(QWidget* parent) : QDialog(parent)
{
  setWindowTitle(tr("Controller Settings"));
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

  m_gamecube_controllers = new GamecubeControllersWidget(this);
  m_wiimote_controllers = new WiimoteControllersWidget(this);
  m_common = new CommonControllersWidget(this);
  CreateMainLayout();
  ConnectWidgets();
}

void ControllersWindow::CreateMainLayout()
{
  auto* layout = new QVBoxLayout();
  m_button_box = new QDialogButtonBox(QDialogButtonBox::Close);

  layout->addWidget(m_gamecube_controllers);
  layout->addWidget(m_wiimote_controllers);
  layout->addWidget(m_common);
  layout->addStretch();
  layout->addWidget(m_button_box);

  WrapInScrollArea(this, layout);
}

void ControllersWindow::ConnectWidgets()
{
  connect(m_button_box, &QDialogButtonBox::rejected, this, &QDialog::reject);
}
