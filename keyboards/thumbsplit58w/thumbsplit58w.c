/* Copyright 2021 Kazuyuki Arimatsu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "thumbsplit58w.h"

#ifdef RGB_MATRIX_ENABLE
/*
// Logical layout of RGBLED index
[
  [ 27, 20, 19, 11, 10, 9 , 8 , 36, 37, 38, 46, 47, 54, 55 ], 
  [  26, 21, 18, 12, 0 , 7 , 35, 28, 39, 45, 48, 53,   56, ],
  [   25, 22, 17, 13, 1 , 6 , 34, 29, 40, 44, 49, 52, 57,  ],
  [    24, 23, 16, 14, 2 , 5 , 33, 30, 41, 43, 50,   51,   ],
  [                15, 3 , 4 , 32, 31, 42,                 ],
]

// Top left corner position in unit (center position for rotated keys)
[
  [ 0   , 1   , 2   , 3   , 4   , 5   , 6   , 7   , 8   , 9    . 10   , 11   , 12   , 13 ], 
  [ 0   , 1.5 , 2.5 , 3.5 , 4.5 , 5.5 , 6.5 , 7.5 , 8.5 , 9.5  . 10.5 , 11.5 , 12.5 ,    ],
  [ 0.25, 1.75, 2.75, 3.75, 4.75, 5.75, 6.75, 7.75, 8.75, 9.75 . 10.75, 11.75, 12.75,    ],
  [ 0.75, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25, 9.25, 10.25. 11.25, 12.25,           ],
  [                   3.55, 5.25, 6.25, 7.25, 8.25, 8.95                                 ],
]

// Key cap size (set 0 for rotated keys)
[
  [ 1  , 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1  , 1 ],
  [ 1.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5,   ],
  [ 1.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1  ,   ],
  [ 1.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,        ],
  [            1, 0, 0, 0, 0, 1,                 ],
]
*/

  led_config_t g_led_config = { {
  // Key Matrix to LED Index (Left 0-27)
    { 27    , 20    , 19    , 11    , 10    , 9     , 8     , }, 
    { 26    , 21    , 18    , 12    , 0     , 7     , NO_LED, }, 
    { 25    , 22    , 17    , 13    , 1     , 6     , NO_LED, }, 
    { 24    , 23    , 16    , 14    , 2     , 5     , NO_LED, }, 
    { NO_LED, NO_LED, NO_LED, 15    , 3     , 4     , NO_LED, }, 
  // Key Matrix to LED Index (Right 28-57)
    { 36    , 37    , 38    , 46    , 47    , 54    , 55    , }, 
    { 35    , 28    , 39    , 45    , 48    , 53    , 56    , }, 
    { 34    , 29    , 40    , 44    , 49    , 52    , 57    , }, 
    { 33    , 30    , 41    , 43    , 50    , 51    , NO_LED, }, 
    { 32    , 31    , 42    , NO_LED, NO_LED, NO_LED, NO_LED, }, 
  }, {
  // LED Index to Physical Position
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, 
  }, {
  // LED Index to Flag
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 
} };

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif

