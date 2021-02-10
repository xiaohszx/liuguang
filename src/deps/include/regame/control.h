/*
 * Copyright 2020-present Ksyun
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#pragma pack(push, 1)
enum class ControlType : uint8_t {
  KEYBOARD = 0,
  KEYBOARD_VK,
  MOUSE,
  GAMEPAD,
  JOYSTICK, // use GAMEPAD instead
  PING,
  PONG
};

struct ControlBase {
  ControlType type;
  uint8_t flags;
  uint32_t timestamp;
};

struct ControlPing : public ControlBase {
};

struct ControlKeyboard : public ControlBase {
  uint16_t key_code;
};

struct ControlJoystickAxis : public ControlBase {
  uint8_t axis_index;
  uint16_t coordinates;
};

struct ControlJoystickButton : public ControlBase {
  uint16_t button;
};

struct ControlJoystickHat : public ControlBase {
  uint8_t hat;
};

union ControlElement {
  ControlBase base;
  ControlPing ping;
  ControlKeyboard keyboard;
  ControlJoystickAxis gamepad_axis;
  ControlJoystickButton gamepad_button;
  ControlJoystickHat gamepad_hat;
};
#pragma pack(pop)

constexpr uint8_t kControlKeyboardFlagUp = 0x01;
constexpr uint8_t kControlKeyboardFlagDown = 0x02;

constexpr uint8_t kControlJoystickFlagNone = 0x00;
constexpr uint8_t kControlJoystickFlagHat = 0x01;
constexpr uint8_t kControlJoystickFlagAxis = 0x02;
constexpr uint8_t kControlJoystickFlagDown = 0x04;
constexpr uint8_t kControlJoystickFlagUp = 0x08;
constexpr uint8_t kControlJoystickFlagButton = 0x10;
