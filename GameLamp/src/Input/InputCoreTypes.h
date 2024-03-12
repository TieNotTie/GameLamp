#pragma once

#include <memory>
#include <string>

namespace Lamp {
	
	enum class MouseButtons : uint8_t
	{
		Left = 0,
		Middle,
		Right,
		Thumb0,
		Thumb1,
		Invalid,
	};

	enum class ButtonStates : uint8_t
	{
		Pressed = 0,
		Released,
		Hold,
		Invalid,
	};
	
	enum class EventTypes : uint8_t
	{
		KeyboardEvent = 0,
		MouseEvent,
		WindowEvent,
	};

	class Key
	{
		Key() 
			: m_NameHash{}, m_IsModifierKey{false}
		{}

		Key(const std::string& name, bool isModifierKey = false )
			: m_Name{name}, m_NameHash{getHash(name)}, m_IsModifierKey{isModifierKey}
		{}
	public:
		std::string getName() const { return m_Name; }

		inline bool isModifierKey() const {return m_IsModifierKey; }

		// overload operators
		friend bool operator==(const Key& left, const Key& right);
		friend bool operator!=(const Key& left, const Key& right)
		{
			return !(left == right);
		}
		// TODO: Replace somehow string comparison
		friend bool operator<(const Key& left, const Key& right) { return left.m_Name < right.m_Name; }

	private: 

		friend struct EKeys;
		// "Jenkins one at a time" hash function
		uint32_t getHash(const std::string& name)
		{
			uint32_t hash = 0;
			size_t i = 0;
			const char* cstr = name.c_str();

			while (i != name.size())
			{
				hash += cstr[i++];
				hash += hash << 10;
				hash ^= hash >> 6;
			}
			hash += hash << 3;
			hash ^= hash >> 11;
			hash += hash << 15;

			return hash;
		}

	private:

		const std::string m_Name;
		// To avoid string comparison 
		const uint32_t m_NameHash;

		const bool m_IsModifierKey;

	};

	class ModifierKeysState
	{
	public:
		ModifierKeysState()
			: m_IsLeftShiftDown{false},
			  m_IsRightShiftDown{false},
			  m_IsLeftControlDown{false},
			  m_IsRightControlDown{false},
			  m_IsLeftAltDown{false},
			  m_IsRightAltDown{false},
			  m_IsLeftCommandDown{false},
			  m_IsRightCommandDown{false},
			  m_IsCapsLocked{false},
			  m_IsNumLocked{false}
		{}
	
		ModifierKeysState(	const bool IsLeftShiftDown,
							const bool IsRightShiftDown,
							const bool IsLeftControlDown,
							const bool IsRightControlDown,
							const bool IsLeftAltDown,
							const bool IsRightAltDown,
							const bool IsLeftCommandDown,
							const bool IsRightCommandDown,
							const bool AreCapsLocked,
							const bool IsNumLocked)
			:	m_IsLeftShiftDown{ IsLeftShiftDown },
				m_IsRightShiftDown{ IsRightShiftDown },
				m_IsLeftControlDown{ IsLeftControlDown },
				m_IsRightControlDown{ IsRightControlDown },
				m_IsLeftAltDown{ IsLeftAltDown },
				m_IsRightAltDown{ IsRightAltDown },
				m_IsLeftCommandDown{ IsLeftCommandDown },
				m_IsRightCommandDown{ IsRightCommandDown },
				m_IsCapsLocked{ AreCapsLocked },
				m_IsNumLocked{IsNumLocked}
		{}

		inline bool isAnyShiftDown() const
		{
			return m_IsLeftShiftDown || m_IsRightShiftDown;
		}

		inline bool isLeftShifDown() const
		{
			return m_IsLeftShiftDown;
		}

		inline bool isRightShiftDown() const
		{
			return m_IsRightShiftDown;
		}

		inline bool isAnyControlDown() const
		{
			return m_IsLeftControlDown || m_IsRightControlDown;
		}

		inline bool isLeftControlDown() const
		{
			return m_IsLeftControlDown;
		}

		inline bool isRightControlDown() const
		{
			return m_IsRightControlDown;
		}

		inline bool isAnyAltDown() const
		{
			return m_IsLeftAltDown || m_IsRightAltDown;
		}

		inline bool isLeftAltDown() const
		{
			return m_IsLeftAltDown;
		}

		inline bool isRightAltDown() const
		{
			return m_IsRightAltDown;
		}

		/*
		 * Mac-specific key. On windows platform, the 'win' key
		*/
		inline bool isAnyCommandDown() const
		{
			return m_IsLeftCommandDown || m_IsRightCommandDown;
		}

		inline bool isLeftCommandDown() const
		{
			return m_IsLeftCommandDown;
		}

		inline bool isRightCommandDown() const
		{
			return m_IsRightCommandDown;
		}

		inline bool isCapsLocked() const
		{
			return m_IsCapsLocked;
		}

		inline bool isNumLocked() const { return m_IsNumLocked; }

	private:

		uint16_t m_IsLeftShiftDown		: 1;
		uint16_t m_IsRightShiftDown		: 1;
		uint16_t m_IsLeftControlDown	: 1;
		uint16_t m_IsRightControlDown	: 1;
		uint16_t m_IsLeftAltDown		: 1;
		uint16_t m_IsRightAltDown		: 1;
		uint16_t m_IsLeftCommandDown	: 1;
		uint16_t m_IsRightCommandDown	: 1;
		uint16_t m_IsCapsLocked			: 1;
		uint16_t m_IsNumLocked			: 1;
	};

	struct EKeys
	{
		static const Key AnyKey;

		static const Key MouseScrollUp;
		static const Key MouseScrollDown;

		static const Key MouseLeftButton;
		static const Key MouseRightButton;
		static const Key MouseMiddleButton;
		static const Key MouseThumbButton0;
		static const Key MouseThumbButton1;

		static const Key BackSpace;
		static const Key Tab;
		static const Key Enter;
		static const Key Pause;
		static const Key Menu;

		static const Key CapsLock;
		static const Key Escape;
		static const Key SpaceBar;
		static const Key PageUp;
		static const Key PageDown;
		static const Key End;
		static const Key Home;

		static const Key Left;
		static const Key Up;
		static const Key Right;
		static const Key Down;

		static const Key Insert;
		static const Key Delete;

		static const Key Zero;
		static const Key One;
		static const Key Two;
		static const Key Three;
		static const Key Four;
		static const Key Five;
		static const Key Six;
		static const Key Seven;
		static const Key Eight;
		static const Key Nine;

		static const Key A;
		static const Key B;
		static const Key C;
		static const Key D;
		static const Key E;
		static const Key F;
		static const Key G;
		static const Key H;
		static const Key I;
		static const Key J;
		static const Key K;
		static const Key L;
		static const Key M;
		static const Key N;
		static const Key O;
		static const Key P;
		static const Key Q;
		static const Key R;
		static const Key S;
		static const Key T;
		static const Key U;
		static const Key V;
		static const Key W;
		static const Key X;
		static const Key Y;
		static const Key Z;

		static const Key NumPadZero;
		static const Key NumPadOne;
		static const Key NumPadTwo;
		static const Key NumPadThree;
		static const Key NumPadFour;
		static const Key NumPadFive;
		static const Key NumPadSix;
		static const Key NumPadSeven;
		static const Key NumPadEight;
		static const Key NumPadNine;
		static const Key NumPadEnter;

		static const Key Multiply;
		static const Key Add;
		static const Key Subtract;
		static const Key Decimal;
		static const Key Divide;

		static const Key F1;
		static const Key F2;
		static const Key F3;
		static const Key F4;
		static const Key F5;
		static const Key F6;
		static const Key F7;
		static const Key F8;
		static const Key F9;
		static const Key F10;
		static const Key F11;
		static const Key F12;

		static const Key NumLock;
		static const Key ScrollLock;
		static const Key PrintScreen;

		static const Key LeftShift;
		static const Key RightShift;
		static const Key LeftControl;
		static const Key RightControl;
		static const Key LeftAlt;
		static const Key RightAlt;
		static const Key LeftCommand;
		static const Key RightCommand;

		static const Key Semicolon;
		static const Key Equals;
		static const Key Comma;
		static const Key Period;
		static const Key Slash;
		static const Key LeftBracket;
		static const Key Backslash;
		static const Key RightBracket;
		static const Key Apostrophe;

		static const Key Delete;

		static const Key Invalid;

		static const std::string NAME_KeyboardCategory;
		static const std::string NAME_MouseCategory;

	};

}
