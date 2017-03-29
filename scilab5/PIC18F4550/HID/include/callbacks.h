/*
 * Firmware framework for USB I/O on PIC 18F2455 (and siblings)
 * Copyright (C) 2005 Alexander Enzmann
 * adapted to MCC18 by Alberto Maccioni on 1/8/09
 * re-adapted to SDCC 2.9.0 by Enrique Olivares (EOL)on 22/06/10
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA
 * or see <http://www.gnu.org/licenses/>
 */

#ifndef CALLBACKS_H
#define CALLBACKS_H

// These are the callbacks expected by the USB HID code.  Each must be
// at least stub functions for the firmware to compile and link correctly.
/* @brief  Handle a control input report.
 * @param
 */
void  GetInputReport (unsigned char reportID);
/* @brief Handle control out.  This might be an alternate way of processing
 * an output report, so all that's needed is to point the output pointer to the
 * output buffer.
 * Initialization for a SET_REPORT request.  This routine will be invoked during
 * the setup stage and is used to set up the buffer for receiving data from the host.
 * @param reportID. Report Identification 
 */
void  SetupOutputReport (unsigned char reportID);
/* @brief // Post processing for a SET_REPORT request.  After all the data has
// been delivered from host to device, this will be invoked to perform
// application specific processing.
 * @param
 */
void  SetOutputReport (unsigned char reportID);
/* @brief // Handle a feature report request on the control pipe.
 * @param
 */
void  GetFeatureReport (unsigned char reportID);
/* @brief // Initialization for a SET_FEATURE request.  This routine will be
// invoked during the setup stage and is used to set up the buffer
// for receiving data from the host.
 * @param 
 * @return 
 */
void  SetupFeatureReport (unsigned char reportID);
/* @brief // Post processing for a SET_FEATURE request.  After all the data has
// been delivered from host to device, this will be invoked to perform
// application specific processing.
 * @param 
 * @return 
 */
void  SetFeatureReport (unsigned char reportID);
#endif //CALLBACKS_H
