/*
    RPG Paper Maker Copyright (C) 2017-2021 Wano

    RPG Paper Maker engine is under proprietary license.
    This source code is also copyrighted.

    Use Commercial edition for commercial use of your games.
    See RPG Paper Maker EULA here:
        http://rpg-paper-maker.com/index.php/eula.
*/

#ifndef SYSTEMDATAS_H
#define SYSTEMDATAS_H

#include <QStandardItemModel>
#include "serializable.h"
#include "primitivevalue.h"
#include "systemtranslatable.h"
#include "systemplaysong.h"

// -------------------------------------------------------
//
//  CLASS SystemDatas
//
//  Contains all the system datas regrouping general project datas,
//  and menus datas.
//  The data file is located in Content/Datas/system.json
//
// -------------------------------------------------------

class SystemDatas : public Serializable
{
public:
    static const QString JSON_PROJECT_NAME;
    static const QString JSON_SCREEN_WIDTH;
    static const QString JSON_SCREEN_HEIGHT;
    static const QString JSON_IS_SCREEN_WINDOW;
    static const QString JSON_COLORS;
    static const QString JSON_ITEMS_TYPES;
    static const QString JSON_INVENTORY_FILTERS;
    static const QString JSON_MAIN_MENU_COMMANDS;
    static const QString JSON_HEROES_STATISTICS;
    static const QString JSON_WINDOW_SKINS;
    static const QString JSON_CAMERA_PROPERTIES;
    static const QString JSON_DETECTIONS;
    static const QString JSON_SPEED;
    static const QString JSON_FREQUENCIES;
    static const QString JSON_FONT_SIZES;
    static const QString JSON_FONT_NAMES;
    static const QString JSON_LAST_MAJOR_VERSION;
    static const QString JSON_LAST_MINOR_VERSION;
    static const QString JSON_MOUNTAIN_COLLISION_HEIGHT;
    static const QString JSON_MOUNTAIN_COLLISION_ANGLE;
    static const QString JSON_SOUND_CURSOR;
    static const QString JSON_SOUND_CONFIRMATION;
    static const QString JSON_SOUND_CANCEL;
    static const QString JSON_SOUND_IMPOSSIBLE;
    static const QString JSON_DIALOG_BOX_OPTIONS;
    static const QString JSON_SKY_BOXES;
    static const QString JSON_ANTIALIASING;
    static const QString JSON_MAP_FRAME_DURATION;
    static const QString JSON_BATTLERS_FRAMES;
    static const QString JSON_BATTLERS_COLUMNS;
    static const QString JSON_PRICE_SOLD_ITEM;
    static const QString JSON_ENTER_NAME_TABLE;
    static const bool DEFAULT_ANTIALIASING;
    static const int DEFAULT_MAP_FRAME_DURATION;
    static const int DEFAULT_BATTLERS_FRAMES;
    static const int DEFAULT_BATTLERS_COLUMNS;
    static const double DEFAULT_PRICE_SOLD_ITEM;

    SystemDatas();
    virtual ~SystemDatas();

    void read(QString path);
    SystemDatas(QString path);
    SystemTranslatable * projectName() const;
    int screenWidth() const;
    void setScreenWidth(int w);
    int screenHeight() const;
    void setScreenHeight(int h);
    bool isScreenWindow() const;
    void setIsScreenWinow(bool b);
    int portionsRay() const;
    void setPortionRay(int p);
    int squareSize() const;
    void setSquareSize(int i);
    PrimitiveValue * mountainCollisionHeight() const;
    PrimitiveValue * mountainCollisionAngle() const;
    PrimitiveValue * mapFrameDuration() const;
    PrimitiveValue * priceSoldItem() const;
    QList<QList<QString>> enterNameTable() const;
    void setEnterNameTable(QList<QList<QString>> enterNameTable);
    int idMapHero() const;
    void setIdMapHero(int i);
    int idObjectHero() const;
    void setIdObjectHero(int i);
    QString pathBR() const;
    void setPathBR(QString p);
    int framesAnimation() const;
    void setFramesAnimation(int f);
    int battlersFrames() const;
    void setBattlersFrames(int battlersFrames);
    int battlersColumns() const;
    void setBattlersColumns(int battlersColumns);
    bool showBB() const;
    void setShowBB(bool b);
    bool antialiasing() const;
    void setAntialiasing(bool aa);
    QStandardItemModel * modelColors() const;
    QStandardItemModel * modelCurrencies() const;
    QStandardItemModel * modelItemsTypes() const;
    QStandardItemModel * modelInventoryFilters() const;
    QStandardItemModel * modelMainMenuCommands() const;
    QStandardItemModel * modelHeroesStatistics() const;
    QStandardItemModel * modelWindowSkins() const;
    QStandardItemModel * modelcameraProperties() const;
    QStandardItemModel * modelDetections() const;
    QStandardItemModel * modelSpeed() const;
    QStandardItemModel * modelFrequencies() const;
    QStandardItemModel * modelFontSizes() const;
    QStandardItemModel * modelFontNames() const;
    QStandardItemModel * modelSkyBoxes() const;
    int lastMajorVersion() const;
    void setLastMajorVersion(int v);
    int lastMinorVersion() const;
    void setLastMinorVersion(int v);
    SystemPlaySong * soundCursor() const;
    SystemPlaySong * soundConfirmation() const;
    SystemPlaySong * soundCancel() const;
    SystemPlaySong * soundImpossible() const;
    EventCommand * dialogBoxOptions() const;
    void setDialogBoxOptions(EventCommand *command);

    void setDefault();
    void setDefaultColors();
    void setDefaultCurrencies();
    void setDefaultItemsTypes();
    void setDefaultInventoryFilters();
    void setDefaultMainMenuCommands();
    void setDefaultHeroesStatistics();
    void setDefaultWindowSkins();
    void setDefaultCameraProperties();
    void setDefaultDetections();
    void setDefaultSpeed();
    void setDefaultFrequencies();
    void setDefaultFontSizes();
    void setDefaultFontNames();
    void setDefaultSounds();
    void setDefaultDialogBoxOptions();
    void setdefaultEnterNameOptions();
    void setDefaultSkyBoxes();

    virtual void read(const QJsonObject &json);
    virtual void write(QJsonObject &json) const;

private:
    SystemTranslatable *m_projectName;
    int m_screenWidth;
    int m_screenHeight;
    bool m_isScreenWindow;
    int m_portionsRay;
    int m_squareSize;
    PrimitiveValue *m_mountainCollisionHeight;
    PrimitiveValue *m_mountainCollisionAngle;
    PrimitiveValue *m_mapFrameDuration;
    PrimitiveValue *m_priceSoldItem;
    QList<QList<QString>> m_enterNameTable;
    int m_idMapHero;
    int m_idObjectHero;
    QString m_pathBR;
    int m_framesAnimation;
    int m_battlersFrames;
    int m_battlersColumns;
    bool m_showBB;
    bool m_antialiasing;
    QStandardItemModel *m_modelColors;
    QStandardItemModel *m_modelCurrencies;
    QStandardItemModel *m_modelItemsTypes;
    QStandardItemModel *m_modelInventoryFilters;
    QStandardItemModel *m_modelMainMenuCommands;
    QStandardItemModel *m_modelHeroesStatistics;
    QStandardItemModel *m_modelWindowSkins;
    QStandardItemModel *m_modelCameraProperties;
    QStandardItemModel *m_modelDetections;
    QStandardItemModel *m_modelSpeed;
    QStandardItemModel *m_modelFrequencies;
    QStandardItemModel *m_modelFontSizes;
    QStandardItemModel *m_modelFontNames;
    QStandardItemModel *m_modelSkyBoxes;
    int m_lastMajorVersion;
    int m_lastMinorVersion;
    SystemPlaySong *m_soundCursor;
    SystemPlaySong *m_soundConfirmation;
    SystemPlaySong *m_soundCancel;
    SystemPlaySong *m_soundImpossible;
    EventCommand *m_dialogBoxOptions;
};

#endif // SYSTEMDATAS_H
