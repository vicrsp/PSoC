/*******************************************************************************
* File Name: WaveDAC8.c
* Version 2.0
*
* Description:
*  This file provides the source code for the 8-bit Waveform DAC 
*  (WaveDAC8) Component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "WaveDAC8.h"

uint8  WaveDAC8_initVar = 0u;

const uint8 CYCODE WaveDAC8_wave1[WaveDAC8_WAVE1_LENGTH] = { 165u,162u,158u,154u,151u,144u,133u,122u,115u,108u,97u,90u,79u,75u,68u,61u,54u,50u,47u,47u,43u,43u,43u,47u,50u,57u,61u,72u,83u,90u,101u,108u,119u,126u,133u,144u,151u,162u,165u,169u,176u,176u,176u,176u,172u,172u,169u,162u,158u,147u,140u,129u,119u,111u,101u,90u,79u,72u,61u,57u,54u,50u,47u,43u,47u,50u,47u,50u,57u,65u,72u,83u,93u,101u,108u,115u,126u,133u,144u,147u,158u,165u,169u,172u,176u,176u,180u,180u,180u,176u,172u,162u,154u,144u,133u,122u,111u,108u,97u,86u,79u,75u,65u,57u,54u,50u,47u,47u,47u,47u,47u,50u,57u,65u,75u,83u,93u,104u,115u,122u,133u,136u,144u,154u,158u,165u,169u,172u,172u,176u,176u,172u,169u,162u,154u,147u,140u,129u,119u,111u,101u,93u,83u,75u,65u,61u,54u,47u,47u,43u,47u,43u,47u,47u,50u,54u,61u,68u,75u,86u,93u,101u,111u,122u,129u,136u,144u,154u,158u,165u,172u,172u,176u,176u,180u,176u,172u,165u,158u,147u,140u,129u,119u,111u,101u,90u,83u,75u,72u,61u,54u,50u,47u,43u,43u,43u,43u,43u,50u,54u,65u,75u,86u,93u,104u,111u,122u,129u,140u,147u,158u,162u,169u,172u,172u,172u,172u,172u,169u,162u,158u,154u,147u,136u,129u,122u,115u,104u,97u,90u,79u,72u,65u,57u,57u,54u,50u,50u,50u,54u,54u,61u,68u,75u,83u,90u,101u,108u,115u,126u,136u,144u,151u,158u,165u,169u,172u,176u,176u,180u,180u,176u,172u,169u,162u,151u,147u,140u,133u,122u,119u,108u,97u,90u,79u,72u,68u,61u,57u,54u,54u,54u,54u,57u,61u,65u,72u,79u,90u,101u,108u,115u,126u,136u,140u,151u,158u,162u,172u,180u,183u,187u,187u,187u,187u,183u,176u,172u,169u,162u,154u,140u,133u,122u,111u,104u,93u,86u,75u,72u,65u,65u,61u,61u,61u,61u,61u,65u,68u,75u,83u,90u,97u,104u,115u,122u,133u,140u,147u,154u,158u,165u,172u,176u,180u,180u,183u,183u,180u,176u,172u,165u,154u,147u,136u,129u,119u,108u,101u,90u,83u,75u,72u,65u,65u,61u,61u,57u,57u,57u,57u,61u,68u,75u,90u,90u,101u,108u,119u,126u,133u,144u,151u,162u,172u,180u,187u,194u,194u,198u,198u,198u,194u,190u,180u,176u,162u,154u,144u,136u,126u,115u,104u,97u,86u,79u,72u,68u,65u,61u,61u,61u,65u,65u,68u,72u,75u,83u,90u,97u,108u,111u,122u,126u,136u,144u,154u,162u,169u,172u,176u,180u,183u,183u,187u,187u,183u,180u,172u,172u,154u,151u,136u,126u,115u,108u,101u,90u,83u,75u,68u,65u,61u,57u,54u,54u,54u,57u,61u,68u,75u,83u,90u,101u,111u,122u,129u,136u,147u,154u,165u,172u,180u,180u,187u,187u,187u,187u,187u,183u,180u,176u,169u,158u,147u,136u,129u,119u,111u,104u,90u,83u,79u,72u,68u,65u,57u,57u,54u,57u,57u,61u,65u,72u,79u,86u,97u,108u,115u,126u,133u,144u,154u,162u,169u,176u,180u,183u,183u,183u,183u,183u,180u,176u,176u,165u,158u,151u,140u,133u,122u,115u,108u,101u,90u,79u,68u,65u,57u,54u,54u,57u,57u,57u,61u,61u,68u,72u,79u,86u,90u,101u,108u,119u,126u,133u,140u,151u,158u,162u,162u,165u,165u,165u,165u,158u,154u,147u,140u,133u,119u,111u,101u,90u,83u,72u,65u,57u,43u,36u,29u,22u,14u,11u,7u,7u,7u,7u,4u,7u,7u,11u,22u,25u,40u,50u,61u,72u,79u,93u,101u,111u,122u,126u,136u,144u,154u,158u,165u,169u,169u,172u,172u,172u,169u,165u,162u,151u,151u,144u,136u,129u,122u,115u,108u,104u,101u,97u,97u,101u,101u,108u,111u,119u,126u,136u,147u,158u,169u,180u,187u,198u,208u,215u,223u,233u,237u,241u,244u,241u,241u,237u,233u,226u,223u,215u,205u,194u,187u,176u,169u,162u,154u,144u,136u,129u,122u,115u,111u,108u,104u,104u,104u,104u,104u,108u,115u,122u,129u,140u,147u,154u,162u,172u,180u,187u,198u,205u,212u,215u,223u,226u,230u,226u,226u,223u,219u,215u,205u,194u,187u,172u,162u,151u,140u,129u,119u,108u,97u,90u,79u,75u,68u,65u,57u,65u,57u,61u,61u,68u,68u,79u,83u,90u,97u,104u,111u,119u,129u,136u,144u,151u,158u,162u,165u,165u,165u,165u,165u,162u,158u,154u,151u,140u,133u,122u,111u,104u,93u,86u,75u,65u,57u,50u,43u,36u,32u,32u,29u,32u,32u,36u,40u,47u,54u,61u,72u,79u,90u,97u,111u,122u,133u,140u,144u,151u,154u,158u,158u,162u,162u,162u,165u,162u,158u,154u,151u,140u,133u,122u,115u,104u,93u,86u,83u,72u,65u,57u,50u,47u,43u,40u,40u,36u,40u,40u,54u,61u,68u,72u,83u,90u,101u,108u,115u,122u,133u,144u,154u,162u,169u,172u,176u,176u,172u,172u,172u,162u,162u,151u,144u,136u,129u,119u,111u,101u,90u,79u,68u,57u,54u,47u,40u,36u,32u,29u,32u,36u,40u,47u,54u,61u,68u,79u,86u,97u,108u,115u,122u,133u,144u,151u,158u,165u,169u,172u,176u,176u,176u,176u,172u,165u,162u,151u,144u,129u,122u,111u,101u,93u,83u,72u,68u,57u,50u,43u,40u,40u,40u,40u,40u,47u,50u,57u,61u,72u,79u,90u,97u,104u,115u,122u,129u,140u,144u,154u,162u,165u,169u,172u,172u,172u,172u,169u,165u,162u,151u,147u,136u,129u,115u,108u,104u,90u,79u,72u,65u,57u,50u,47u,43u,43u,40u,40u,43u,47u,50u,54u,61u,72u,79u,90u,101u,111u,122u,133u,144u,151u,158u,165u,172u,176u,176u,176u,180u,180u,180u,172u,169u,162u,151u,144u,133u,122u,108u,104u,93u,83u,75u,68u,57u,54u,50u,47u,43u,43u,43u,43u,50u,54u,61u,65u,75u,83u,93u,104u,111u,122u,129u,140u,147u,154u,162u,165u,169u,172u,180u,180u,180u,180u,180u,176u,172u,165u,154u,144u,133u,119u,108u,101u,86u,79u,72u,65u,57u,54u,50u,47u,47u,43u,43u,47u,47u,54u,61u,65u,79u,86u,93u,104u,115u,122u,133u,140u,151u,158u,165u,169u,172u,172u,176u,176u,176u,172u,169u,165u,158u,151u,144u,133u,122u,115u,108u,97u,86u,79u,68u,61u,50u,47u,43u,40u,36u,32u,32u,36u,43u,50u,57u,65u,75u,83u,90u,101u,111u,119u,133u,140u,151u,158u,162u,169u,172u,176u,176u,180u,176u,172u,165u,158u,151u,144u,133u,122u,108u,101u,86u,75u,65u,57u,50u,47u,43u,36u,36u,36u,36u,36u,40u,43u,50u,61u,68u,75u,83u,93u,104u,108u,119u,126u,133u,140u,147u,147u,158u,154u,158u,158u,158u,158u,154u,151u,144u,140u,133u,126u,119u,108u,101u,93u,83u,75u,65u,61u,50u,47u,40u,40u,36u,32u,36u,36u,40u,47u,54u,61u,72u,79u,86u,93u,104u,111u,119u,126u,133u,136u,144u,147u,151u,154u,154u,154u,158u,154u,151u,147u,140u,133u,126u,115u,108u,97u,93u,83u,75u,65u,57u,50u,43u,36u,32u,29u,29u,29u,32u,32u,40u,43u,50u,57u,68u,79u,86u,93u,104u,111u,122u,129u,136u,144u,151u,158u,162u,165u,165u,165u,165u,162u,158u,151u,144u,133u,126u,111u,104u,93u,83u,75u,65u,57u,50u,47u,40u,36u,36u,36u,32u,36u,36u,40u,47u,54u,57u,68u,75u,86u,97u,108u,115u,126u,129u,140u,147u,154u,158u,162u,165u,165u,165u,165u,165u,165u,162u,154u,147u,140u,133u,126u,115u,108u,101u,90u,83u,75u,72u,65u,61u,57u,54u,54u,54u,54u,57u,57u,65u,65u,75u,83u,90u,97u,108u,115u,126u,133u,144u,154u,165u,169u,176u,183u,187u,187u,190u,187u,187u,183u,180u,172u,165u,154u,147u,136u,129u,119u,108u,101u,90u,83u,79u,75u,75u,72u,75u,75u,75u,79u,86u,93u,97u,108u,115u,126u,133u,144u,154u,162u,172u,180u,187u,198u,201u,208u,212u,212u,215u,219u,219u,219u,212u,208u,201u,194u,187u,180u,169u,158u,151u,144u,136u,129u,119u,111u,108u,104u,101u,97u,93u,93u,93u,97u,104u,111u,119u,129u,140u,151u,158u,172u,180u,190u,201u,208u,219u,226u,230u,241u,244u,241u,248u,248u,244u,241u,237u,230u,219u,215u,205u,194u,187u,180u,172u,165u,158u,144u,136u,126u,119u,115u,111u,111u,115u,115u,119u,122u,129u,136u,144u,151u,162u,169u,176u,183u,194u,205u,215u,223u,230u,237u,241u,244u,248u,248u,248u,248u,248u,244u,241u,233u,223u,215u,201u,190u,180u,169u,158u,147u,136u,129u,119u,108u,108u,104u,104u,104u,104u,108u,111u,119u,126u,133u,144u,151u,158u,169u,183u,190u,198u,208u,219u,226u,233u,237u,237u,241u,241u,241u,241u,237u,233u,226u,219u,212u,198u,190u,180u,169u,162u,154u,144u,136u,129u,122u,115u,111u,108u,101u,101u,97u,97u,101u,108u,111u,122u,129u,140u,147u,158u,165u,176u,183u,198u,205u,215u,219u,223u,230u,230u,230u,230u,230u,226u,223u,219u,215u,205u,194u,187u,180u,172u,162u,151u,144u,133u,122u,115u,108u,101u,97u,90u,90u,86u,86u,86u,86u,93u,104u,111u,119u,129u,140u,151u,162u,172u,180u,187u,194u,201u,208u,212u,215u,219u,219u,219u,219u,215u,208u,201u,190u,180u,172u,162u,154u,144u,136u,129u,122u,108u,101u,93u,90u,83u,83u,79u,79u,83u,83u,86u,90u,97u,104u,111u,122u,133u,136u,147u,154u,162u,172u,183u,190u,198u,205u,208u,212u,212u,212u,212u,208u,205u,198u,187u,180u,172u,165u,151u,140u,133u,122u,115u,104u,97u,86u,79u,72u,68u,65u,68u,68u,65u,68u,72u,75u,86u,90u,101u,111u,122u,133u,140u,147u,158u,165u,172u,176u,183u,187u,194u,198u,198u,198u,198u,198u,190u,190u,183u,176u,165u,154u,147u,136u,126u,115u,104u,93u,83u,79u,72u,68u,65u,61u,65u,61u,61u,65u,68u,72u,75u,83u,93u,104u,115u,122u,133u,140u,151u,158u,162u,169u,176u,183u,183u,183u,183u,183u,183u,180u,172u,169u,162u,151u,144u,136u,129u,119u,108u,101u,90u,79u,72u,65u,57u,57u,54u,50u,54u,54u,57u,61u,65u,72u,83u,90u,101u,108u,119u,129u,136u,144u,151u,162u,165u,176u,180u,183u,187u,187u,187u,183u,180u,172u,165u,154u,144u,136u,129u,119u,115u,108u,101u,90u,79u,72u,61u,57u,47u,50u,47u,47u,47u,50u,50u,61u,68u,72u,83u,90u,97u,108u,119u,126u,133u,140u,147u,151u,158u,169u,169u,169u,176u,176u,176u,172u,172u,162u,154u,147u,136u,126u,119u,108u,97u,90u,79u,72u,61u,57u,50u,50u,47u,43u,43u,43u,43u,47u,50u,57u,65u,75u,83u,93u,101u,111u,119u,129u,136u,147u,154u,165u,169u,172u,176u,180u,180u,180u,176u,172u,169u,162u,158u,151u,144u,133u,122u,111u,101u,90u,79u,68u,61u,54u,40u,43u,40u,40u,36u,36u,36u,40u,47u,50u,57u,68u,75u,86u,93u,104u,115u,126u,136u,144u,151u,162u,165u,172u,169u,169u,172u,172u,169u,165u,158u,147u,144u,133u,122u,111u,108u,97u,86u,79u,68u,57u,50u,47u,40u,40u,36u,36u,36u,40u,43u,47u,54u,61u,68u,75u,86u,93u,101u,111u,122u,129u,136u,147u,154u,162u,165u,165u,165u,169u,169u,169u,169u,165u,158u,151u,140u,126u,115u,108u,97u,86u,75u,68u,57u,50u,43u,36u,36u,36u,29u,32u,32u,36u,43u,47u,57u,68u,75u,86u,97u,104u,111u,119u,122u,129u,136u,147u,151u,154u,162u,162u,162u,165u,162u,158u,154u,151u,144u,140u,129u,122u,115u,104u,97u,86u,79u,68u,57u,54u,47u,43u,40u,36u,36u,36u,40u,43u,47u,54u,61u,68u,79u,90u,97u,108u,115u,126u,133u,140u,151u,158u,158u,158u,165u,162u,165u,162u,162u,162u,151u,147u,136u,129u,119u,111u,101u,90u,83u,75u,65u,57u,50u,43u,40u,40u,40u,36u,36u,36u,40u,43u,50u,57u,65u,72u,83u,90u,101u,104u,115u,126u,133u,140u,151u,158u,162u,165u,165u,165u,165u,162u,158u,154u,147u,140u,133u,122u,111u,104u,97u,90u,79u,72u,65u,54u,47u,40u,36u,36u,32u,32u,32u,36u,40u,47u,54u,61u,68u,79u,86u,97u,104u,111u,122u,129u,140u,151u,158u,162u,169u,169u,169u,172u,169u,169u,165u,162u,154u,147u,133u,126u,115u,104u,90u,79u,72u,61u,54u,47u,43u,40u,36u,32u,29u,25u,25u,29u,36u,40u,47u,57u,68u,79u,90u,97u,108u,119u,122u,133u,140u,147u,151u,154u,154u,158u,162u,162u,162u,162u,154u,151u,144u,133u,126u,115u,104u,93u,83u,75u,65u,61u,47u,43u,43u,40u,40u,36u,36u,40u,43u,47u,54u,61u,68u,75u,83u,93u,101u,111u,119u,126u,133u,144u,151u,158u,158u,162u,162u,162u,162u,154u,154u,151u,144u,136u,129u,122u,111u,108u,97u,90u,79u,72u,61u,54u,47u,40u,36u,36u,32u,32u,32u,36u,36u,43u,50u,57u,65u,75u,83u,90u,101u,111u,122u,129u,136u,147u,154u,158u,162u,165u,165u,169u,165u,162u,158u,154u,147u,140u,129u,122u,111u,101u,93u,83u,75u,68u,57u,50u,43u,40u,40u,32u,36u,36u,40u,43u,47u,50u,57u,68u,75u,83u,90u,101u,111u,119u,126u,129u,144u,151u,154u,158u,162u,162u,165u,165u,165u,162u,158u,151u,144u,136u,126u,115u,108u,97u,90u,83u,75u,65u,57u,50u,43u,36u,36u,32u,29u,29u,32u,36u,40u,50u,57u,65u,75u,83u,93u,104u,111u,122u,133u,144u,151u,158u,165u,169u,169u,169u,172u,169u,169u,165u,162u,154u,147u,140u,133u,119u,115u,101u,90u,83u,75u,68u,65u,61u,57u,54u,47u,43u,43u,43u,47u,50u,54u,57u,68u,72u,79u,90u,97u,108u,115u,122u,129u,136u,140u,147u,151u,154u,158u,162u,162u,162u,158u,154u,147u,140u,133u,129u,119u,108u,101u,90u,83u,72u,65u,57u,50u,43u,40u,36u,36u,36u,36u,40u,40u,47u,57u,61u,75u,83u,93u,101u,111u,122u,129u,136u,144u,151u,158u,162u,162u,165u,165u,165u,165u,162u,158u,154u,151u,144u,136u,126u,119u,108u,97u,90u,79u,72u,61u,54u,47u,43u,40u,36u,36u,36u,40u,40u,47u,54u,61u,72u,83u,90u,101u,111u,122u,129u,136u,144u,154u,162u,169u,169u,176u,176u,180u,176u,176u,169u,162u,154u,147u,136u,133u,119u,108u,97u,90u,79u,68u,57u,47u,43u,40u,36u,32u,32u,36u,36u,43u,47u,54u,57u,65u,75u,83u,90u,101u,108u,115u,126u,136u,147u,154u,162u,169u,172u,172u,176u,176u,172u,172u,172u,162u,154u,144u,136u,126u,115u,104u,97u,86u,79u,72u,61u,57u,50u,47u,43u,40u,40u,43u,40u,47u,54u,61u,68u,75u,83u,93u,101u,111u,122u,129u,140u,147u,158u,162u,172u,172u,180u,180u,183u,180u,180u,172u,165u,158u,151u,144u,133u,122u,119u,108u,101u,90u,79u,68u,61u,54u,50u,47u,47u,47u,47u,47u,50u,54u,61u,68u,79u,86u,97u,104u,111u,119u,129u,133u,144u,151u,162u,165u,169u,172u,172u,176u,172u,172u,169u,162u,154u,147u,136u,129u,119u,111u,101u,93u,90u,83u,75u,68u,65u,57u,54u,50u,47u,47u,47u,50u,54u,61u,65u,72u,83u,90u,101u,108u,115u,122u,133u,144u,151u,162u,169u,172u,180u,180u,183u,180u,180u,180u,172u,169u,162u,151u,140u,133u,122u,115u,104u,97u,86u,75u,72u,61u,54u,50u,50u,47u,43u,47u,50u,54u,61u,61u,68u,75u,83u,93u,104u,115u,122u,133u,144u,151u,162u,172u,180u,183u,183u,183u,180u,180u,172u,169u,165u,158u,151u,144u,136u,126u,115u,104u,97u,83u,75u,68u,61u,54u,54u,50u,47u,47u,43u,40u,43u,43u,50u,57u,65u,75u,83u,93u,104u,115u,126u,136u,147u,158u,165u,172u,180u,183u,183u,183u,180u,180u,176u,165u,162u,151u,144u,133u,126u,119u,108u,101u,90u,83u,72u,61u,54u,47u,43u,36u,36u,36u,40u,40u,43u,50u,57u,65u,75u,86u,93u,104u,115u,126u,133u,144u,151u,158u,169u,172u,176u,180u,180u,180u,180u,176u,172u,165u,158u,151u,140u,129u,122u,111u,108u,93u,90u,79u,72u,68u,61u,57u,54u,54u,54u,54u,54u,57u,61u,68u,75u,86u,93u,101u,111u,119u,126u,133u,144u,147u,158u,162u,169u,169u,180u,180u,183u,183u,187u,183u,180u,172u,169u,158u,147u,136u,129u,122u,111u,101u,93u,83u,75u,72u,68u,68u,65u,61u,61u,61u,61u,65u,72u,75u,83u,90u,101u,108u,119u,126u,136u,144u,151u,162u,169u,172u,180u,180u,180u,180u,180u,176u,172u,172u,169u,162u,151u,147u,140u,129u,122u,111u,104u,93u,86u,75u,68u,65u,57u,54u,50u,54u,47u,50u,50u,57u,68u,75u,86u,97u,108u,115u,122u,133u,140u,144u,154u,162u,169u,176u,183u,187u,190u,190u,190u,187u,183u,180u,172u,169u,158u,147u,136u,126u,122u,108u,101u,93u,83u,75u,68u,65u,61u,61u,61u,61u,61u,65u,68u,72u,79u,86u,101u,108u,119u,129u,136u,144u,151u,158u,165u,172u,180u,187u,194u,201u,198u,201u,201u,194u,187u,180u,169u,158u,144u,133u,126u,115u,108u,101u,90u,86u,75u,72u,68u,65u,61u,61u,61u,61u,65u,61u,72u,79u,86u,97u,104u,111u,119u,129u,136u,147u,154u,165u,172u,180u,183u,190u,190u,190u,190u,187u,187u,180u,176u,169u,165u,158u,151u,140u,133u,126u,119u,108u,93u,86u,79u,75u,68u,65u,65u,65u,61u,68u,68u,75u,83u,90u,97u,104u,115u,122u,129u,133u,144u,147u,158u,162u,169u,172u,176u,183u,183u,183u,187u,187u,183u,180u,172u,169u,158u,151u,140u,133u,122u,115u,101u,97u,90u,75u,72u,65u,61u,57u,57u,54u,57u,57u,61u,65u,72u,79u,90u,101u,108u,119u,126u,133u,144u,154u,162u,172u,180u,190u,190u,194u,194u,194u,190u,190u,183u,176u,165u,162u,151u,136u,129u,119u,111u,101u,93u,83u,75u,68u,61u,57u,57u,57u,54u,54u,54u,57u,61u,61u,72u,75u,83u,90u,93u,101u,108u,119u,126u,136u,140u,151u,158u,162u,162u,162u,162u,162u,162u,154u,151u,144u,136u,126u,115u,108u,97u,86u,75u,65u,54u,40u,29u,25u,14u,11u,7u,4u,0u,0u,0u,4u,7u,14u,25u,36u,47u,57u,72u,79u,90u,101u,108u,119u,126u,136u,147u,154u,158u,165u,172u,176u,180u,180u,180u,176u,176u,172u,169u,165u,158u,154u,151u,144u,136u,129u,122u,119u,119u,115u,115u,111u,115u,115u,115u,119u,122u,129u,140u,151u,162u,172u,183u,194u,205u,212u,219u,230u,233u,237u,244u,248u,251u,255u,255u,251u,248u,237u,226u,219u,208u,198u,190u,180u,165u,154u,147u,136u,129u,122u,111u,111u,108u,108u,104u,104u,104u,108u,111u,115u,122u,129u,136u,147u,154u,162u,172u,180u,190u,198u,205u,212u,219u,223u,223u,226u,230u,226u,226u,223u,219u,208u,205u,194u,183u,172u,158u,144u,133u,122u,111u,97u,86u,75u,68u,61u,54u,50u,47u,47u,50u,54u,61u,68u,75u,83u,90u,97u,104u,115u,122u,129u,144u,147u,154u,162u,165u,165u,165u,165u,162u,165u,162u,158u,151u,144u,136u,126u,119u,108u,97u,90u,79u,72u,61u,61u,54u,47u,43u,40u,36u,36u,36u,36u,36u,40u,47u,54u,61u,72u,79u,90u,101u,108u,119u,126u,136u,144u,154u,158u,165u,169u,172u,176u,172u,172u,169u,165u,158u,151u,144u,136u,126u,119u,111u,101u,90u,79u,68u,57u,47u,36u,36u,25u,25u,25u,29u,29u,36u,40u,47u,57u,65u,75u,83u,93u,104u,111u,122u,129u,136u,147u,154u,162u,165u,169u,169u,172u,172u,169u,162u,158u,151u,144u,133u,126u,115u,104u,97u,86u,79u,72u,65u,57u,50u,47u,43u,40u,40u,40u,40u,43u,47u,57u,65u,72u,83u,90u,101u,108u,119u,126u,136u,144u,151u,158u,165u,169u,169u,169u,169u,169u,165u,162u,162u,151u,140u,133u,126u,119u,108u,97u,86u,79u,68u,61u,54u,47u,43u,40u,40u,40u,40u,40u,43u,47u,54u,61u,68u,79u,86u,97u,108u,115u,122u,129u,136u,144u,151u,158u,165u,169u,172u,172u,176u,172u,172u,165u,158u,151u,140u,133u,126u,119u,108u,101u,93u,86u,79u,68u,61u,54u,47u,43u,43u,40u,43u,43u,47u,50u,57u,65u,72u,79u,93u,101u,111u,122u,129u,140u,147u,154u,162u,169u,172u,176u,176u,176u,176u,172u,169u,165u,158u,147u,140u,129u,122u,111u,101u,90u,79u,72u,65u,57u,50u,47u,43u,40u,40u,40u,40u,43u,50u,54u,61u,68u,79u,90u,101u,111u,115u,126u,133u,140u,147u,154u,158u,162u,165u,169u,169u,169u,169u,165u,162u,158u,151u,144u,133u,122u,111u,104u,97u,83u,75u,68u,61u,54u,50u,47u,43u,40u,43u,43u,43u,47u,54u,61u,72u,79u,90u,101u,111u,119u,129u,136u,144u,154u,158u,165u,172u,172u,172u,172u,172u,172u,169u,165u,158u,151u,144u,136u,126u,115u,108u,101u,93u,83u,75u,65u,61u,54u,50u,43u,43u,43u,43u,43u,47u,50u,57u,65u,72u,83u,90u,101u,108u,115u,122u,133u,140u,151u,158u,162u,162u,165u,165u,165u,165u,165u,162u,158u,154u,147u,140u,133u,126u,115u,108u,97u,90u,79u,68u,61u,54u,43u,40u,36u,36u,36u,40u,40u,47u,54u,61u,65u,75u,79u,86u,93u,104u,111u,119u,129u,136u,144u,151u,158u,162u,165u,165u,169u,165u,165u,158u,154u,147u,133u,129u,122u,108u,97u,90u,79u,68u,65u,57u,50u,43u,40u,36u,36u,32u,36u,32u,36u,40u,47u,54u,61u,72u,83u,97u,104u,115u,122u,133u,144u,151u,162u,169u,169u,172u,172u,176u,176u,172u,169u,162u,151u,144u,133u,122u,111u,104u,93u,86u,79u,68u,61u,57u,54u,47u,43u,40u,40u,36u,32u,32u,32u,36u,43u,50u,57u,68u,75u,86u,97u,108u,119u,129u,136u,147u,151u,158u,162u,162u,165u,162u,162u,158u,154u,151u,144u,133u,126u,115u,108u,97u,90u,79u,72u,61u,57u,47u,43u,40u,36u,36u,36u,36u,40u,43u,50u,54u,61u,72u,79u,93u,101u,111u,119u,129u,136u,147u,154u,162u,165u,169u,169u,169u,169u,169u,165u,165u,162u,158u,147u,136u,126u,119u,108u,101u,90u,83u,75u,68u,65u,61u,57u,57u,54u,54u,50u,54u,54u,61u,68u,75u,83u,90u,97u,104u,111u,126u,133u,144u,151u,162u,169u,176u,180u,183u,187u,187u,187u,190u,187u,183u,176u,172u,165u,158u,147u,140u,133u,122u,115u,108u,101u,93u,86u,83u,83u,79u,75u,75u,75u,75u,75u,83u,90u,101u,111u,122u,133u,140u,147u,158u,165u,172u,183u,190u,198u,208u,212u,215u,215u,219u,219u,219u,215u,208u,205u,194u,187u,176u,169u,158u,147u,140u,133u,122u,115u,111u,104u,101u,97u,97u,97u,97u,101u,104u,111u,119u,129u,136u,147u,154u,165u,176u,183u,194u,205u,212u,219u,226u,226u,230u,233u,237u,241u,244u,248u,241u,237u,230u,223u,212u,205u,194u,180u,172u,162u,154u,144u,136u,129u,126u,119u,119u,115u,111u,115u,115u,119u,122u,126u,133u,140u,151u,162u,172u,180u,187u,194u,205u,212u,219u,226u,233u,241u,244u,248u,248u,251u,251u,248u,244u,241u,233u,226u,215u,208u,198u,187u,180u,169u,162u,154u,144u,136u,129u,122u,119u,115u,111u,111u,111u,115u,119u,126u,133u,147u,154u,165u,176u,183u,190u,201u,205u,212u,219u,223u,226u,233u,233u,233u,233u,233u,233u,230u,226u,219u,212u };
const uint8 CYCODE WaveDAC8_wave2[WaveDAC8_WAVE2_LENGTH] = { 128u,133u,138u,143u,148u,153u,158u,163u,168u,173u,178u,184u,189u,194u,199u,204u,209u,214u,219u,224u,230u,235u,240u,245u,250u,255u,250u,245u,240u,235u,230u,224u,219u,214u,209u,204u,199u,194u,189u,184u,178u,173u,168u,163u,158u,153u,148u,143u,138u,133u,128u,122u,117u,112u,107u,102u,97u,92u,87u,82u,76u,71u,66u,61u,56u,51u,46u,41u,36u,31u,25u,20u,15u,10u,5u,0u,5u,10u,15u,20u,25u,31u,36u,41u,46u,51u,56u,61u,66u,71u,77u,82u,87u,92u,97u,102u,107u,112u,117u,122u };

static uint8  WaveDAC8_Wave1Chan;
static uint8  WaveDAC8_Wave2Chan;
static uint8  WaveDAC8_Wave1TD;
static uint8  WaveDAC8_Wave2TD;


/*******************************************************************************
* Function Name: WaveDAC8_Init
********************************************************************************
*
* Summary:
*  Initializes component with parameters set in the customizer.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void WaveDAC8_Init(void) 
{
	WaveDAC8_VDAC8_Init();
	WaveDAC8_VDAC8_SetSpeed(WaveDAC8_HIGHSPEED);
	WaveDAC8_VDAC8_SetRange(WaveDAC8_DAC_RANGE);

	#if(WaveDAC8_DAC_MODE == WaveDAC8_CURRENT_MODE)
		WaveDAC8_IDAC8_SetPolarity(WaveDAC8_DAC_POL);
	#endif /* WaveDAC8_DAC_MODE == WaveDAC8_CURRENT_MODE */

	#if(WaveDAC8_OUT_MODE == WaveDAC8_BUFFER_MODE)
	   WaveDAC8_BuffAmp_Init();
	#endif /* WaveDAC8_OUT_MODE == WaveDAC8_BUFFER_MODE */

	/* Get the TD Number for the DMA channel 1 and 2   */
	WaveDAC8_Wave1TD = CyDmaTdAllocate();
	WaveDAC8_Wave2TD = CyDmaTdAllocate();
	
	/* Initialize waveform pointers  */
	WaveDAC8_Wave1Setup(WaveDAC8_wave1, WaveDAC8_WAVE1_LENGTH) ;
	WaveDAC8_Wave2Setup(WaveDAC8_wave2, WaveDAC8_WAVE2_LENGTH) ;
	
	/* Initialize the internal clock if one present  */
	#if defined(WaveDAC8_DacClk_PHASE)
	   WaveDAC8_DacClk_SetPhase(WaveDAC8_CLK_PHASE_0nS);
	#endif /* defined(WaveDAC8_DacClk_PHASE) */
}


/*******************************************************************************
* Function Name: WaveDAC8_Enable
********************************************************************************
*  
* Summary: 
*  Enables the DAC block and DMA operation.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void WaveDAC8_Enable(void) 
{
	WaveDAC8_VDAC8_Enable();

	#if(WaveDAC8_OUT_MODE == WaveDAC8_BUFFER_MODE)
	   WaveDAC8_BuffAmp_Enable();
	#endif /* WaveDAC8_OUT_MODE == WaveDAC8_BUFFER_MODE */

	/* 
	* Enable the channel. It is configured to remember the TD value so that
	* it can be restored from the place where it has been stopped.
	*/
	(void)CyDmaChEnable(WaveDAC8_Wave1Chan, 1u);
	(void)CyDmaChEnable(WaveDAC8_Wave2Chan, 1u);
	
	/* set the initial value */
	WaveDAC8_SetValue(0u);
	
	#if(WaveDAC8_CLOCK_SRC == WaveDAC8_CLOCK_INT)  	
	   WaveDAC8_DacClk_Start();
	#endif /* WaveDAC8_CLOCK_SRC == WaveDAC8_CLOCK_INT */
}


/*******************************************************************************
* Function Name: WaveDAC8_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as 
*  executing the stop function.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void WaveDAC8_Start(void) 
{
	/* If not Initialized then initialize all required hardware and software */
	if(WaveDAC8_initVar == 0u)
	{
		WaveDAC8_Init();
		WaveDAC8_initVar = 1u;
	}
	
	WaveDAC8_Enable();
}


/*******************************************************************************
* Function Name: WaveDAC8_StartEx
********************************************************************************
*
* Summary:
*  The StartEx function sets pointers and sizes for both waveforms
*  and then starts the component.
*
* Parameters:  
*   uint8 * wavePtr1:     Pointer to the waveform 1 array.
*   uint16  sampleSize1:  The amount of samples in the waveform 1.
*   uint8 * wavePtr2:     Pointer to the waveform 2 array.
*   uint16  sampleSize2:  The amount of samples in the waveform 2.
*
* Return: 
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void WaveDAC8_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)

{
	WaveDAC8_Wave1Setup(wavePtr1, sampleSize1);
	WaveDAC8_Wave2Setup(wavePtr2, sampleSize2);
	WaveDAC8_Start();
}


/*******************************************************************************
* Function Name: WaveDAC8_Stop
********************************************************************************
*
* Summary:
*  Stops the clock (if internal), disables the DMA channels
*  and powers down the DAC.
*
* Parameters:  
*  None  
*
* Return: 
*  None
*
*******************************************************************************/
void WaveDAC8_Stop(void) 
{
	/* Turn off internal clock, if one present */
	#if(WaveDAC8_CLOCK_SRC == WaveDAC8_CLOCK_INT)  	
	   WaveDAC8_DacClk_Stop();
	#endif /* WaveDAC8_CLOCK_SRC == WaveDAC8_CLOCK_INT */
	
	/* Disble DMA channels */
	(void)CyDmaChDisable(WaveDAC8_Wave1Chan);
	(void)CyDmaChDisable(WaveDAC8_Wave2Chan);

	/* Disable power to DAC */
	WaveDAC8_VDAC8_Stop();
}


/*******************************************************************************
* Function Name: WaveDAC8_Wave1Setup
********************************************************************************
*
* Summary:
*  Sets pointer and size for waveform 1.                                    
*
* Parameters:  
*  uint8 * WavePtr:     Pointer to the waveform array.
*  uint16  SampleSize:  The amount of samples in the waveform.
*
* Return: 
*  None 
*
*******************************************************************************/
void WaveDAC8_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)

{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (WaveDAC8_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
		
		WaveDAC8_Wave1Chan = WaveDAC8_Wave1_DMA_DmaInitialize(
		WaveDAC8_Wave1_DMA_BYTES_PER_BURST, WaveDAC8_Wave1_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		WaveDAC8_Wave1Chan = WaveDAC8_Wave1_DMA_DmaInitialize(
		WaveDAC8_Wave1_DMA_BYTES_PER_BURST, WaveDAC8_Wave1_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(WaveDAC8_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
    * Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(WaveDAC8_Wave1TD, sampleSize, WaveDAC8_Wave1TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)WaveDAC8_Wave1_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(WaveDAC8_Wave1TD, LO16((uint32)wavePtr), LO16(WaveDAC8_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(WaveDAC8_Wave1Chan, WaveDAC8_Wave1TD);
}


/*******************************************************************************
* Function Name: WaveDAC8_Wave2Setup
********************************************************************************
*
* Summary:
*  Sets pointer and size for waveform 2.                                    
*
* Parameters:  
*  uint8 * WavePtr:     Pointer to the waveform array.
*  uint16  SampleSize:  The amount of samples in the waveform.
*
* Return: 
*  None
*
*******************************************************************************/
void WaveDAC8_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
 
{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (WaveDAC8_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
			
		WaveDAC8_Wave2Chan = WaveDAC8_Wave2_DMA_DmaInitialize(
		WaveDAC8_Wave2_DMA_BYTES_PER_BURST, WaveDAC8_Wave2_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		WaveDAC8_Wave2Chan = WaveDAC8_Wave2_DMA_DmaInitialize(
		WaveDAC8_Wave2_DMA_BYTES_PER_BURST, WaveDAC8_Wave2_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(WaveDAC8_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
	* Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(WaveDAC8_Wave2TD, sampleSize, WaveDAC8_Wave2TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)WaveDAC8_Wave2_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(WaveDAC8_Wave2TD, LO16((uint32)wavePtr), LO16(WaveDAC8_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(WaveDAC8_Wave2Chan, WaveDAC8_Wave2TD);
}


/* [] END OF FILE */
