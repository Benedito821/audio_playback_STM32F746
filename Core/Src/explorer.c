/**
  ******************************************************************************
  * @file    Audio/Audio_playback_and_record/Src/explorer.c 
  * @author  MCD Application Team
  * @brief   This file provides USB Key drive configuration
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "waveplayer.h"
#include "explorer.h"
#include "usb_host.h"
/* Private typedef -----------------------------------------------------------*/
extern char USBHPath[4];
FILELIST_FileTypeDef FileList;
uint16_t NumObs = 0;

/*Exported variables----------------------------------------------------------*/
extern USBH_HandleTypeDef hUsbHostFS;
extern ApplicationTypeDef Appli_state;
extern FATFS USBH_fatfs;
extern FIL WavFile;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Copies disk content in the explorer list.
  * @param  None
  * @retval Operation result
  */
FRESULT AUDIO_StorageParse(void)
{
  FRESULT res = FR_OK;
  FILINFO fno;
  DIR dir;
  char *fn;
  
  res = f_opendir(&dir, USBHPath);
  FileList.ptr = 0;
  
  if(res == FR_OK)
  {
    while(USBH_MSC_IsReady(&hUsbHostFS)) // change from hUSBHost to hUsbHostFS
    {
      res = f_readdir(&dir, &fno);
      if(res != FR_OK || fno.fname[0] == 0)
      {
        break;
      }
      if(fno.fname[0] == '.')
      {
        continue;
      }
      fn = fno.fname;
      
      if(FileList.ptr < FILEMGR_LIST_DEPDTH)
      {
        if((fno.fattrib & AM_DIR) == 0)
        {
          if((strstr(fn, "wav")) || (strstr(fn, "WAV")))
          {
            strncpy((char *)FileList.file[FileList.ptr].name, (char *)fn, FILEMGR_FILE_NAME_SIZE);
            FileList.file[FileList.ptr].type = FILETYPE_FILE;
            FileList.ptr++;
          }
        }
      }   
    }
  }
  NumObs = FileList.ptr;
  f_closedir(&dir);
  return res;
}


/**
  * @brief  Shows audio file (*.wav) on the root
  * @param  None
  * @retval None
  */
uint8_t AUDIO_ShowWavFiles(void)
{
  uint8_t i = 0;
  uint8_t line_idx = 0;

  if(AUDIO_StorageParse() ==  FR_OK)
  {
    if(FileList.ptr > 0)
    {
      for(i = 0; i < FileList.ptr; i++)
      {
        line_idx++;
      }
      return 0;
    }
    return 1;
  }
  return 2;
}

/**
  * @brief  Gets Wav Object Number.
  * @param  None
  * @retval None
  */
uint16_t AUDIO_GetWavObjectNumber(void)
{
	if (AUDIO_StorageParse() == FR_OK)
		return NumObs;
}
