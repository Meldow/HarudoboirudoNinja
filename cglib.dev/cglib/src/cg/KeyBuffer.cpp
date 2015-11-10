// This file is part of CGLib.
//
// CGLib is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// CGLib is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CGLib; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// Copyright 2012 Carlos Martinho

#include "KeyBuffer.h"

namespace cg {

	SINGLETON_IMPLEMENTATION_NO_CONSTRUCTOR(KeyBuffer)

	KeyBuffer::KeyBuffer() {
        int i;
        for (i = 0; i < KEY_MAX; i++) {
            _key[i] = false;
        }
        for (i = 0; i < SPECIAL_KEY_MAX; i++) {
            _specialKey[i] = false;
        }
		_modifierKeys = 0;
    }
	inline
	unsigned char KeyBuffer::modifyAlphaKey(unsigned char key) {
		if((_modifierKeys & GLUT_ACTIVE_CTRL) && (key <= 26)) { 
			return (key + 96);
		} else if((_modifierKeys & GLUT_ACTIVE_SHIFT) && (key >= 'A' && key <= 'Z')) {
			return (key + 32);
		} else {
			return key;
		}
	}
	void KeyBuffer::pressKey(unsigned char key) {
		if(_modifierKeys) {
			key = modifyAlphaKey(key);
		}
        _key[key] = true;
    }
    void KeyBuffer::releaseKey(unsigned char key) {
		if(_modifierKeys) {
			key = modifyAlphaKey(key);
		}
        _key[key] = false;
    }
    bool KeyBuffer::isKeyDown(unsigned char key) const {
        return _key[key];
    }
    bool KeyBuffer::isKeyUp(unsigned char key) const {
        return !_key[key];
    }
    void KeyBuffer::pressSpecialKey(int key) {
		switch(key) {
		case GLUT_KEY_SHIFT_L:
		case GLUT_KEY_SHIFT_R:
			_modifierKeys |= GLUT_ACTIVE_SHIFT; 
			break;
		case GLUT_KEY_CTRL_L:
		case GLUT_KEY_CTRL_R:
			_modifierKeys |= GLUT_ACTIVE_CTRL; 
			break;
		case GLUT_KEY_ALT_L:
		case GLUT_KEY_ALT_R:
			_modifierKeys |= GLUT_ACTIVE_ALT; 
			break;
		};
        _specialKey[key] = true;
    }
    void KeyBuffer::releaseSpecialKey(int key) {
		switch(key) {
		case GLUT_KEY_SHIFT_L:
		case GLUT_KEY_SHIFT_R:
			_modifierKeys &= ~GLUT_ACTIVE_SHIFT; 
			break;
		case GLUT_KEY_CTRL_L:
		case GLUT_KEY_CTRL_R:
			_modifierKeys &= ~GLUT_ACTIVE_CTRL; 
			break;
		case GLUT_KEY_ALT_L:
		case GLUT_KEY_ALT_R:
			_modifierKeys &= ~GLUT_ACTIVE_ALT; 
			break;
		};
        _specialKey[key] = false;
    }
    bool KeyBuffer::isSpecialKeyDown(int key) const {
        return _specialKey[key];
    }
    bool KeyBuffer::isSpecialKeyUp(int key) const {
        return !_specialKey[key];
    }
	bool KeyBuffer::isShiftActive() const {
		return (_modifierKeys & GLUT_ACTIVE_SHIFT) != 0;
	}
	bool KeyBuffer::isCtrlActive() const {
		return (_modifierKeys & GLUT_ACTIVE_CTRL) != 0;
	}
	bool KeyBuffer::isAltActive() const {
		return (_modifierKeys & GLUT_ACTIVE_ALT) != 0;
	}
}
