/*
    RPG Paper Maker Copyright (C) 2017-2021 Wano

    RPG Paper Maker engine is under proprietary license.
    This source code is also copyrighted.

    Use Commercial edition for commercial use of your games.
    See RPG Paper Maker EULA here:
        http://rpg-paper-maker.com/index.php/eula.
*/

#include "dialogcommandstartshopmenu.h"
#include "ui_dialogcommandstartshopmenu.h"
#include "systemcommanditemprice.h"
#include "rpm.h"

// -------------------------------------------------------
//
//  CONSTRUCTOR / DESTRUCTOR / GET / SET
//
// -------------------------------------------------------

DialogCommandStartShopMenu::DialogCommandStartShopMenu(EventCommand *command,
    QStandardItemModel *properties, QStandardItemModel *parameters, QWidget *parent) :
    DialogCommand(parent),
    m_properties(properties),
    m_parameters(parameters),
    m_modelItemPrice(new QStandardItemModel),
    ui(new Ui::DialogCommandStartShopMenu)
{
    ui->setupUi(this);
    this->initializePrimitives();
    if (command != nullptr)
    {
        initialize(command);
    }
    this->translate();
}

DialogCommandStartShopMenu::~DialogCommandStartShopMenu()
{
    delete ui;
    SuperListItem::deleteModel(m_modelItemPrice);
}

// -------------------------------------------------------
//
//  INTERMEDIARY FUNCTIONS
//
// -------------------------------------------------------

void DialogCommandStartShopMenu::translate()
{

}

// -------------------------------------------------------

void DialogCommandStartShopMenu::initializePrimitives()
{
    ui->treeViewItemPrice->initializeNewItemInstance(new SystemCommandItemPrice);
    ui->treeViewItemPrice->initializeModel(m_modelItemPrice);
    m_modelItemPrice->appendRow(SuperListItem::getEmptyItem());
    m_modelItemPrice->setHorizontalHeaderLabels(QStringList({RPM::translate(
        Translations::ITEM), RPM::translate(Translations::PRICE), "Stock"}));
    ui->treeViewItemPrice->header()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->treeViewItemPrice->header()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->treeViewItemPrice->header()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->treeViewItemPrice->setCurrentIndex(ui->treeViewItemPrice->getModel()->index(0, 0));
    ui->treeViewItemPrice->setCanBeControled(true);
    ui->panelPrimitiveValueBuyOnly->initializeSwitch(m_parameters, m_properties);
    ui->panelPrimitiveValueBuyOnly->setSwitchValue(false);
    ui->widgetVariableStock->initialize(1);
}

// -------------------------------------------------------
//
//  VIRTUAL FUNCTIONS
//
// -------------------------------------------------------

void DialogCommandStartShopMenu::initialize(EventCommand* command)
{
    int i = 0;
    ui->panelPrimitiveValueBuyOnly->initializeCommand(command, i);
    ui->checkBoxStockShopInstanceID->setChecked(command->valueCommandAt(i++) ==
        RPM::TRUE_BOOL_STRING);
    if (ui->checkBoxStockShopInstanceID->isChecked())
    {
        ui->widgetVariableStock->initialize(command->valueCommandAt(i++).toInt());
    }
    SystemCommandItemPrice *itemPrice;
    int j = 0;
    while (i < command->commandsCount())
    {
        itemPrice = new SystemCommandItemPrice;
        itemPrice->initialize(command, i);
        m_modelItemPrice->insertRow(j, itemPrice->getModelRow());
        j++;
    }
    ui->treeViewItemPrice->setCurrentIndex(ui->treeViewItemPrice->getModel()->index(0, 0));
}

// -------------------------------------------------------

EventCommand * DialogCommandStartShopMenu::getCommand() const
{
    QVector<QString> command;
    ui->panelPrimitiveValueBuyOnly->getCommand(command);
    command.append(ui->checkBoxStockShopInstanceID->isChecked() ? RPM
        ::TRUE_BOOL_STRING : RPM::FALSE_BOOL_STRING);
    if (ui->checkBoxStockShopInstanceID->isChecked())
    {
        command.append(QString::number(ui->widgetVariableStock->currentId()));
    }
    SystemCommandItemPrice *itemPrice;
    for (int i = 0, l = m_modelItemPrice->invisibleRootItem()->rowCount(); i < l; i ++)
    {
        itemPrice = reinterpret_cast<SystemCommandItemPrice *>(SuperListItem
            ::getItemModelAt(m_modelItemPrice, i));
        if (itemPrice != nullptr) {
            itemPrice->getCommand(command);
        }
    }
    return new EventCommand(EventCommandKind::StartShopMenu, command);
}

// -------------------------------------------------------
//
//  SLOTS
//
// -------------------------------------------------------

void DialogCommandStartShopMenu::on_checkBoxStockShopInstanceID_toggled(bool checked)
{
    ui->widgetVariableStock->setEnabled(checked);
}