#include "Filter.h"
#include "Filter_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_ChannelABiquadCoefficients

/* Number of Biquad sections are: 1 */

const uint8 CYCODE Filter_ChannelABiquadCoefficients[Filter_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0x91u, 0xF9u, 0x3Fu, 0x00u, /* Section(0)_A0, 0.99960732460022 */

 0x3Au, 0x31u, 0x80u, 0x00u, /* Section(0)_A1, -1.99699544906616 */

 0x91u, 0xF9u, 0x3Fu, 0x00u, /* Section(0)_A2, 0.99960732460022 */

 0xC6u, 0xCEu, 0x7Fu, 0x00u, /* Section(0)_B1, -1.99699544906616 */

 0xDDu, 0x0Cu, 0xC0u, 0x00u, /* Section(0)_B2, 0.999214887619019 */
};

