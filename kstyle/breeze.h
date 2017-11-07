#ifndef breeze_h
#define breeze_h

/*************************************************************************
 * Copyright (C) 2014 by Hugo Pereira Da Costa <hugo.pereira@free.fr>    *
 *                                                                       *
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program; if not, write to the                         *
 * Free Software Foundation, Inc.,                                       *
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 *************************************************************************/

#include <QFlags>
#include <QPointer>
#include <QScopedPointer>
#include <QWeakPointer>

namespace Breeze
{

    //*@name convenience typedef
    //@{

    #if QT_VERSION >= 0x050000
    //* scoped pointer convenience typedef
    template <typename T> using WeakPointer = QPointer<T>;
    #else
    //* scoped pointer convenience typedef
    template <typename T> using WeakPointer = QWeakPointer<T>;
    #endif

    //* scoped pointer convenience typedef
    template <typename T> using ScopedPointer = QScopedPointer<T, QScopedPointerPodDeleter>;

    //* disable QStringLiteral for older Qt version
    #if QT_VERSION < 0x050000
    using QStringLiteral = QString;
    #endif

    //@}

    //* metrics
    enum Metrics
    {

        // frames
        Frame_FrameWidth = 2,
        Frame_FrameRadius = 3,

        // layout
        Layout_TopLevelMarginWidth = 15,
        Layout_ChildMarginWidth = 9,
        Layout_DefaultSpacing = 9,

        // line editors
        LineEdit_FrameWidth = 9,

        // menu items
        Menu_FrameWidth = 0,
        MenuItem_MarginWidth = 5,
        MenuItem_ItemSpacing = 6,
        MenuItem_AcceleratorSpace = 24,
        MenuButton_IndicatorWidth = 30,

        // combobox
        ComboBox_FrameWidth = 9,

        // spinbox
        SpinBox_FrameWidth = LineEdit_FrameWidth,
        SpinBox_ArrowButtonWidth = 30,

        // groupbox title margin
        GroupBox_TitleMarginWidth = 9,

        // buttons
        Button_MinWidth = 120,
        Button_MarginWidth = 9,
        Button_ItemSpacing = 6,

        // tool buttons
        ToolButton_MarginWidth = 9,
        ToolButton_ItemSpacing = 6,
        ToolButton_InlineIndicatorWidth = 18,

        // checkboxes and radio buttons
        CheckBox_Size = 25,
        CheckBox_FocusMarginWidth = 4,
        CheckBox_ItemSpacing = 6,

        // menubar items
        MenuBarItem_MarginWidth = 15,
        MenuBarItem_MarginHeight = 9,

        // scrollbars
        ScrollBar_Extend = 30,
        ScrollBar_SliderWidth = 9,
        ScrollBar_MinSliderHeight = 30,
        ScrollBar_NoButtonHeight = (ScrollBar_Extend-ScrollBar_SliderWidth)/2,
        ScrollBar_SingleButtonHeight = ScrollBar_Extend,
        ScrollBar_DoubleButtonHeight = 2*ScrollBar_Extend,

        // toolbars
        ToolBar_FrameWidth = 3,
        ToolBar_HandleExtent = 15,
        ToolBar_HandleWidth = 9,
        ToolBar_SeparatorWidth = 12,
        ToolBar_ExtensionWidth = 30,
        ToolBar_ItemSpacing = 0,

        // progressbars
        ProgressBar_BusyIndicatorSize = 21,
        ProgressBar_Thickness = 9,
        ProgressBar_ItemSpacing = 6,

        // mdi title bar
        TitleBar_MarginWidth = 6,

        // sliders
        Slider_TickLength = 12,
        Slider_TickMarginWidth = 3,
        Slider_GrooveThickness = 9,
        Slider_ControlThickness = 30,

        // tabbar
        TabBar_TabMarginHeight = 6,
        TabBar_TabMarginWidth = 12,
        TabBar_TabMinWidth = 120,
        TabBar_TabMinHeight = 42,
        TabBar_TabItemSpacing = 12,
        TabBar_TabOverlap = 2,
        TabBar_BaseOverlap = 3,

        // tab widget
        TabWidget_MarginWidth = 6,

        // toolbox
        ToolBox_TabMinWidth = 120,
        ToolBox_TabItemSpacing = 6,
        ToolBox_TabMarginWidth = 12,

        // tooltips
        ToolTip_FrameWidth = 5,

        // list headers
        Header_MarginWidth = 9,
        Header_ItemSpacing = 6,
        Header_ArrowSize = 15,

        // tree view
        ItemView_ArrowSize = 15,
        ItemView_ItemMarginWidth = 5,
        SidePanel_ItemMarginWidth = 6,

        // splitter
        Splitter_SplitterWidth = 1,

        // shadow dimensions
        Shadow_Overlap = 3

    };

    //* animation mode
    enum AnimationMode
    {
        AnimationNone = 0,
        AnimationHover = 0x1,
        AnimationFocus = 0x2,
        AnimationEnable = 0x4,
        AnimationPressed = 0x8
    };

    Q_DECLARE_FLAGS(AnimationModes, AnimationMode)

    //* corners
    enum Corner
    {
        CornerTopLeft = 0x1,
        CornerTopRight = 0x2,
        CornerBottomLeft = 0x4,
        CornerBottomRight = 0x8,
        CornersTop = CornerTopLeft|CornerTopRight,
        CornersBottom = CornerBottomLeft|CornerBottomRight,
        CornersLeft = CornerTopLeft|CornerBottomLeft,
        CornersRight = CornerTopRight|CornerBottomRight,
        AllCorners = CornerTopLeft|CornerTopRight|CornerBottomLeft|CornerBottomRight
    };

    Q_DECLARE_FLAGS( Corners, Corner )

    //* sides
    enum Side
    {
        SideLeft = 0x1,
        SideTop = 0x2,
        SideRight = 0x4,
        SideBottom = 0x8,
        AllSides = SideLeft|SideTop|SideRight|SideBottom
    };

    Q_DECLARE_FLAGS( Sides, Side )

    //* checkbox state
    enum CheckBoxState
    {
        CheckOff,
        CheckPartial,
        CheckOn,
        CheckAnimated
    };

    //* radio button state
    enum RadioButtonState
    {
        RadioOff,
        RadioOn,
        RadioAnimated
    };

    //* arrow orientation
    enum ArrowOrientation
    {
        ArrowNone,
        ArrowUp,
        ArrowDown,
        ArrowLeft,
        ArrowRight
    };

    //* button type
    enum ButtonType
    {
        ButtonClose,
        ButtonMaximize,
        ButtonMinimize,
        ButtonRestore
    };

}

Q_DECLARE_OPERATORS_FOR_FLAGS( Breeze::AnimationModes )
Q_DECLARE_OPERATORS_FOR_FLAGS( Breeze::Corners )
Q_DECLARE_OPERATORS_FOR_FLAGS( Breeze::Sides )

#endif
