//
//  AETemplates.h
//  primGen
//
//  Created by Hunyadi J�nos on 2015. 01. 03..
//  Copyright (c) 2015. Janos Hunyadi. All rights reserved.
//

#ifndef MELSCRIPTS_H
#define MELSCRIPTS_H

#include <maya/MString.h>


MString mel_AETemplate()
{
	MString s_aeTemplate = MString() + "//deleteUI AttrEdBaseLocFormLayout;\r\n"
		"global proc AEBaseLocTemplate( string $nodeName )\r\n"
		"{\r\n"
		"	editorTemplate -beginScrollLayout;\r\n"
		"	editorTemplate -beginLayout \"Locator presets\" -collapse 0;\r\n"
		"	editorTemplate -addControl \"presets\";\r\n"
		"	editorTemplate -addControl \"iconType\";\r\n"
		"	editorTemplate -addControl \"2DIconType\";\r\n"
		"	editorTemplate -addSeparator;\r\n"
		"	editorTemplate -addControl \"radius\";\r\n"
		"	editorTemplate -addSeparator;\r\n"
		"	editorTemplate -addControl \"lineWidth\";\r\n"
		"	editorTemplate -addControl \"lineColor\";\r\n"
		"	editorTemplate -addControl \"lineAlpha\";\r\n"
		"	editorTemplate -addSeparator;\r\n"
		"	editorTemplate -addControl \"polygonColor\";\r\n"
		"	editorTemplate -addControl \"polygonAlpha\";\r\n"
		"	editorTemplate -endLayout;\r\n"
		"	\r\n"
		"	editorTemplate -beginLayout \"Visibility switches\" -collapse 0;\r\n"
		"	editorTemplate -addControl \"displayLocatorId\";\r\n"
		"	editorTemplate -addControl \"displayLocator\";\r\n"
		"	editorTemplate -addSeparator;\r\n"
		"	editorTemplate -addControl \"displayLocatorPivot\";\r\n"
		"	editorTemplate -addControl \"displayText\";\r\n"
		"	editorTemplate -addSeparator;\r\n"
		"	editorTemplate -addControl \"drawOnTop\";\r\n"
		"	editorTemplate -endLayout;\r\n"
		"	\r\n"
		"	editorTemplate -beginLayout \"File presets\" -collapse 0;\r\n"
		"	editorTemplate -callCustom \"AE_presetList_BaseLoc_create\" \"AE_presetList_BaseLoc_edit\" \"\";\r\n"
		"	editorTemplate -endLayout;\r\n"
		"	editorTemplate -beginLayout \"Transforms\" -collapse 0;\r\n"
		"	editorTemplate -addControl \"offsetX\";\r\n"
		"	editorTemplate -addControl \"offsetY\";\r\n"
		"	editorTemplate -addControl \"offsetZ\";\r\n"
		"	editorTemplate -addSeparator;\r\n"
		"	editorTemplate -addControl \"rotateX\";\r\n"
		"	editorTemplate -addControl \"rotateY\";\r\n"
		"	editorTemplate -addControl \"rotateZ\";\r\n"
		"	editorTemplate -addSeparator;\r\n"
		"	editorTemplate -addControl \"scaleX\";\r\n"
		"	editorTemplate -addControl \"scaleY\";\r\n"
		"	editorTemplate -addControl \"scaleZ\";\r\n"
		"	editorTemplate -endLayout;\r\n"
		"	editorTemplate -beginLayout \"Draw style\" -collapse 0;\r\n"
		"	editorTemplate -addControl \"lineStyle\";\r\n"
		"	editorTemplate -addControl \"paintStyle\";\r\n"
		"	editorTemplate -endLayout;\r\n"
		"	editorTemplate -beginLayout \"Text\" -collapse 0;\r\n"
		"	editorTemplate -addControl \"textPosition\";\r\n"
		"	editorTemplate -addControl \"textFontSize\";\r\n"
		"	editorTemplate -addSeparator;\r\n"
		"	editorTemplate -addControl \"text\";\r\n"
		"	editorTemplate -addSeparator;\r\n"
		"	editorTemplate -addControl \"fontFaceName\";\r\n"
		"	editorTemplate -addControl \"textAlignment\";\r\n"
		"	editorTemplate -addControl \"textIncline\";\r\n"
		"	editorTemplate -addControl \"textWeight\";\r\n"
		"	editorTemplate -addControl \"textStretch\";\r\n"
		"	editorTemplate -addControl \"textLine\";\r\n"
		"	editorTemplate -addSeparator;\r\n"
		"	editorTemplate -addControl \"textBoxSize\";\r\n"
		"	editorTemplate -addControl \"textBoxColor\";\r\n"
		"	editorTemplate -addControl \"textBoxTransparency\";\r\n"
		"	editorTemplate -endLayout;\r\n"
		"	editorTemplate -beginLayout \"Misc\" -collapse 0;\r\n"
		"	editorTemplate -addControl \"locID\";\r\n"
		"	editorTemplate -endLayout;\r\n"
		"	\r\n"
		"	editorTemplate -beginLayout \"Plug-in Info\" -collapse 0;\r\n"
		"	editorTemplate -callCustom \"AE_bl_website_create\" \"AE_bl_website_edit\" \"\";\r\n"
		"	editorTemplate -endLayout;\r\n"
		"	editorTemplate -suppress \"division\";\r\n"
		"	editorTemplate -suppress \"displayCards\";\r\n"
		"	editorTemplate -suppress \"fadeByDistance\";\r\n"
		"	editorTemplate -suppress \"fadeDistance\";\r\n"
		"	editorTemplate -suppress \"locatorPos\";\r\n"
		"	editorTemplate -suppress \"inPointArray\";\r\n"
		"	editorTemplate -suppress \"inTriangleArray\";\r\n"
		"	AEdependNodeTemplate $nodeName;\r\n"
		"	editorTemplate -addExtraControls;\r\n"
		"	editorTemplate -endScrollLayout;\r\n"
		"}\r\n"
		"global proc AE_presetList_BaseLoc_create(string $attrName)\r\n"
		"{\r\n"
		"    string $nodeName[];\r\n"
		"    tokenize($attrName, \".\", $nodeName);\r\n"
		"    \r\n"
		"    // Crete preset list\r\n"
		"    \r\n"
		"    separator -height 10 -style \"in\";\r\n"
		"	textScrollList -allowMultiSelection false -h 120 \"bl_presets\";\r\n"
		"    setParent ..;\r\n"
		"    // Populate preset list\r\n"
		"    \r\n"
		"    \r\n"
		"    string $bl_pr_path = eval(\"getAttr \" + $nodeName[0] + \".presetFolderPath\");\r\n"
		"    \r\n"
		"    string $enumFields_list[] = `getFileList -fs \"*.blp\" -folder $bl_pr_path`;\r\n"
		"    \r\n"
		"    string $enumName[];\r\n"
		"    \r\n"
		"    \r\n"
		"    for( $i=0; $i<size($enumFields_list); ++$i )\r\n"
		"	{\r\n"
		"	    tokenize($enumFields_list[$i], \".\", $enumName);\r\n"
		"	    textScrollList -edit -append $enumName[0] \"bl_presets\";\r\n"
		"	}\r\n"
		"    \r\n"
		"    // Create add / remove preset icons\r\n"
		"    separator -height 10 -style \"in\";\r\n"
		"    \r\n"
		"    rowLayout -numberOfColumns 5 -h 25 -adjustableColumn 4 -bgc 0.2 0.2 0.2;\r\n"
		"    iconTextButton -w 20 -style \"iconAndTextHorizontal\" -image1 \"baseLoc_Apply.png\" -label \"apply preset\" -bgc 0.3 0.3 0.3 -c  (\"AE_apply_customProfile_BaseLoc \" + $nodeName[0] ) \"bl_pres_appl\";\r\n"
		"	iconTextButton -w 50 -style \"iconAndTextHorizontal\" -image1 \"baseLoc_Plus.png\" -label \"add\" -bgc 0.4 0.4 0.4 -c  (\"AE_add_customProfile_BaseLoc \" + $nodeName[0] ) \"bl_pres_add\";\r\n"
		"	iconTextButton  -w 90 -style \"iconAndTextHorizontal\" -image1 \"baseLoc_Minus.png\" -label \"remove\" -bgc 0.6 0.2 0.3 -c  (\"AE_remove_customProfile_BaseLoc \" + $nodeName[0] ) \"bl_pres_rem\";\r\n"
		"	textField -pht \"Untitled\" \"bl_t_renamePreset\";\r\n"
		"	iconTextButton -w 80 -style \"iconAndTextHorizontal\" -image1 \"baseLoc_Refresh.png\" -label \"refresh\" -bgc 0.6 0.6 0.6 -c  (\"AE_refresh_customProfile_BaseLoc \" + $nodeName[0] ) \"bl_pres_refresh\";\r\n"
		"	\r\n"
		"	setParent ..;\r\n"
		"	\r\n"
		"	separator -height 10 -style \"in\";\r\n"
		"    \r\n"
		"}\r\n"
		"global proc AE_presetList_BaseLoc_edit(string $attrName)\r\n"
		"{\r\n"
		"    string $nodeName[];\r\n"
		"    tokenize($attrName, \".\", $nodeName);\r\n"
		"    \r\n"
		"    iconTextButton -edit -c (\"AE_apply_customProfile_BaseLoc \" + $nodeName[0] ) \"bl_pres_appl\";\r\n"
		"	iconTextButton -edit -c (\"AE_add_customProfile_BaseLoc \" + $nodeName[0] ) \"bl_pres_add\";\r\n"
		"	iconTextButton -edit -c (\"AE_remove_customProfile_BaseLoc \" + $nodeName[0] ) \"bl_pres_rem\";\r\n"
		"	iconTextButton -edit -c (\"AE_refresh_customProfile_BaseLoc \" + $nodeName[0] ) \"bl_pres_refresh\";\r\n"
		"    \r\n"
		"}\r\n"
		"// --------------\r\n"
		"// Custom profile\r\n"
		"global proc AE_refresh_customProfile_BaseLoc(string $nodeName)\r\n"
		"{\r\n"
		"    \r\n"
		"    string $sm_pr_path = eval(\"getAttr \" + $nodeName + \".presetFolderPath\");\r\n"
		"    string $enumFields_list[] = `getFileList -fs \"*.blp\" -folder $sm_pr_path`;\r\n"
		"    \r\n"
		"    string $enumName[];\r\n"
		"    \r\n"
		"    textScrollList -edit -ra \"bl_presets\";\r\n"
		"    \r\n"
		"    for( $i=0; $i<size($enumFields_list); ++$i )\r\n"
		"	{\r\n"
		"	    tokenize($enumFields_list[$i], \".\", $enumName);\r\n"
		"	    textScrollList -edit -append $enumName[0] \"bl_presets\";\r\n"
		"	}\r\n"
		"}\r\n"
		"global proc AE_add_customProfile_BaseLoc(string $attrName)\r\n"
		"{\r\n"
		"    string $nodeName[];\r\n"
		"    tokenize($attrName, \".\", $nodeName);\r\n"
		"    \r\n"
		"    string $newPresetName;\r\n"
		"    $newPresetName = `textField -query -tx \"bl_t_renamePreset\"`;\r\n"
		"    \r\n"
		"    if ($newPresetName == \"\") { $newPresetName = \"untitled\";}\r\n"
		"    \r\n"
		"    string $bl_pr_path = eval(\"getAttr \" + $nodeName[0] + \".presetFolderPath\");\r\n"
		"    \r\n"
		"    string $enumFields_list[] = `getFileList -fs \"*.blp\" -folder $bl_pr_path`;\r\n"
		"    \r\n"
		"    string $enumName[];\r\n"
		"    \r\n"
		"    int $isSame = 0;\r\n"
		"    \r\n"
		"    for( $i=0; $i<size($enumFields_list); ++$i )\r\n"
		"	{\r\n"
		"	    tokenize($enumFields_list[$i], \".\", $enumName);\r\n"
		"	    \r\n"
		"	    if($enumName[0] == $newPresetName)\r\n"
		"	    {\r\n"
		"	        string $conFirmVal = `confirmDialog -title (\"Overwrite \" + $newPresetName) -message \"Are you sure?\"\r\n"
		"    -button \"Yes\" -button \"No\" -defaultButton \"Yes\"\r\n"
		"    -cancelButton \"No\" -dismissString \"No\"`;\r\n"
		"    \r\n"
		"            if($conFirmVal == \"Yes\")\r\n"
		"            {\r\n"
		"                BaseLocCommand -sp $newPresetName -pp $bl_pr_path -bl $nodeName[0];\r\n"
		"                $isSame = 1;\r\n"
		"            }\r\n"
		"            \r\n"
		"            if($conFirmVal == \"No\")\r\n"
		"            {\r\n"
		"                $isSame = 1;\r\n"
		"            }\r\n"
		"	    }\r\n"
		"	    \r\n"
		"	}\r\n"
		"    \r\n"
		"    if( $isSame == 0)\r\n"
		"    {\r\n"
		"        BaseLocCommand -sp $newPresetName -pp $bl_pr_path -bl $nodeName[0];\r\n"
		"    }\r\n"
		"    \r\n"
		"    \r\n"
		"    \r\n"
		"    AE_refresh_customProfile_BaseLoc($nodeName[0]);\r\n"
		"    \r\n"
		"}\r\n"
		"global proc AE_apply_customProfile_BaseLoc(string $attrName)\r\n"
		"{\r\n"
		"    string $nodeName[];\r\n"
		"    tokenize($attrName, \".\", $nodeName);\r\n"
		"    //AE_set_ProfileType(0, $nodeName[0]);\r\n"
		"   \r\n"
		"    \r\n"
		"    string $presetName[];\r\n"
		"    $presetName = `textScrollList -query -si \"bl_presets\"`;\r\n"
		"    \r\n"
		"    if (`textScrollList -query -nsi \"bl_presets\"` != 0)\r\n"
		"    {\r\n"
		"        if ($presetName[0] != \"\") \r\n"
		"        {\r\n"
		"            \r\n"
		"            \r\n"
		"            string $bl_pr_path = eval(\"getAttr \" + $nodeName[0] + \".presetFolderPath\");\r\n"
		"            \r\n"
		"            BaseLocCommand -lp $presetName -pp $bl_pr_path -bl $nodeName[0];\r\n"
		"            \r\n"
		"            textScrollList -edit -si $presetName \"bl_presets\";\r\n"
		"            \r\n"
		"            \r\n"
		"        }\r\n"
		"        \r\n"
		"        eval(\"setAttr \" + $nodeName[0] + \".presets \" + 11);\r\n"
		"    }\r\n"
		"    \r\n"
		"    else\r\n"
		"    {\r\n"
		"        warning -n \"[BaseLoc] No items selected in list\";\r\n"
		"    }\r\n"
		"    \r\n"
		"    AE_refresh_customProfile_BaseLoc($nodeName[0]);\r\n"
		"    \r\n"
		"    \r\n"
		"}\r\n"
		"global proc AE_remove_customProfile_BaseLoc(string $attrName)\r\n"
		"{\r\n"
		"    string $nodeName[];\r\n"
		"    tokenize($attrName, \".\", $nodeName);\r\n"
		"    \r\n"
		"    string $presetName[];\r\n"
		"    $presetName = `textScrollList -query -si \"bl_presets\"`;\r\n"
		"    \r\n"
		"    if ($presetName[0] != \"\") \r\n"
		"    {\r\n"
		"        \r\n"
		"        \r\n"
		"        string $conFirmVal = `confirmDialog -title \"Delete\" -message \"Are you sure?\" -button \"Yes\" -button \"No\" -defaultButton \"Yes\" -cancelButton \"No\" -dismissString \"No\"`;\r\n"
		"    \r\n"
		"            if($conFirmVal == \"Yes\")\r\n"
		"            {\r\n"
		"                string $sm_pr_path = eval(\"getAttr \" + $nodeName[0] + \".presetFolderPath\");\r\n"
		"                sysFile -delete ($sm_pr_path + $presetName[0] + \".blp\");\r\n"
		"                AE_refresh_customProfile_BaseLoc($nodeName[0]);\r\n"
		"            }\r\n"
		"            \r\n"
		"            if($conFirmVal == \"No\")\r\n"
		"            {\r\n"
		"                \r\n"
		"            }\r\n"
		"        \r\n"
		"        \r\n"
		"        \r\n"
		"    }\r\n"
		"    \r\n"
		"    \r\n"
		"}\r\n"
		"global proc AE_bl_launch_website()\r\n"
		"{\r\n"
		"    launch -web \"http://gumroad.com/creativecase\";\r\n"
		"}\r\n"
		"// ----------------------------\r\n"
		"// Global window Create / Edit\r\n"
		"global proc AE_bl_website_create(string $attrName)\r\n"
		"{\r\n"
		"	string $nodeName[];\r\n"
		"    tokenize($attrName, \".\", $nodeName);\r\n"
		"    \r\n"
		"    string $sm_pr_path = eval(\"getAttr \" + $nodeName[0] + \".presetFolderPath\");\r\n"
		"    \r\n"
		"    rowLayout -numberOfColumns 3 -adjustableColumn 2 -bgc 0.2 0.2 0.2;\r\n"
		"    text -al \"left\" -label \"Preset path\";\r\n"
		"    textField -ed false -tx $sm_pr_path;\r\n"
		"    iconTextButton -style \"iconOnly\" -image1 \"baseLoc_CCLogo.png\" -c \"AE_bl_launch_website()\";\r\n"
		"    setParent ..;\r\n"
		"}\r\n"
		"global proc AE_bl_website_edit(string $attrName)\r\n"
		"{\r\n"
		"}\r\n";



	return s_aeTemplate;

}

MString mel_createShelf()
{

	MString s_aeTemplate = MString() + "int $cc_doesShelfExist = `shelfLayout -query -ex \"CreativeCase\"`;"
		"if ($cc_doesShelfExist == true)"
		"{"
		"    string $shelfButtons[] = `shelfLayout -q -ca \"CreativeCase\"`;"
		"    int $ex_b01 = 0;"
		"    "
		"    for( $i=0; $i<size($shelfButtons); ++$i )"
		"    {"
		"        if( `control -exists $shelfButtons[$i]` == true)"
		"        {"
		"            if (`control -q -docTag $shelfButtons[$i]` == \"bl_createBlButton\") {$ex_b01 = 1;}"
		"        }"
		"    }"
		"    "
		"    if ($ex_b01 == 0) {shelfButton -p \"CreativeCase\" -dtg \"bl_createBlButton\" -annotation \"Creates a BaseLocator\" -image1 \"BaseLoc.png\" -command \"BaseLocCommand\";}"
		"    "
		"}"
		"	"
		"if ($cc_doesShelfExist == false)"
		"{"
		"		shelfLayout -cellWidth 33 -cellHeight 33 -p $gShelfTopLevel CreativeCase;"
		"		shelfButton -p \"CreativeCase\" -dtg \"bl_createBlButton\" -annotation \"Creates a BaseLocator\" -image1 \"BaseLoc.png\" -command \"BaseLocCommand\";"
		"}";

	return s_aeTemplate;
}

#endif