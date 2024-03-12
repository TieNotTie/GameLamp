#include "InputCoreTypes.h"

namespace Lamp
{

	bool operator==(const Key& left, const Key& right)
	{
		return left.m_NameHash == right.m_NameHash;
	}

	const Key EKeys::AnyKey("AnyKey");

	const Key EKeys::MouseScrollUp("MouseScrollUp");
	const Key EKeys::MouseScrollDown("MouseScrollDown");

	const Key EKeys::MouseLeftButton("LeftMouseButton");
	const Key EKeys::MouseRightButton("RightMouseButton");
	const Key EKeys::MouseMiddleButton("MiddleMouseButton");
	const Key EKeys::MouseThumbButton0("ThumbMouseButton0");
	const Key EKeys::MouseThumbButton1("ThumbMouseButton1");

	const Key EKeys::BackSpace("BackSpace");
	const Key EKeys::Tab("Tab");
	const Key EKeys::Enter("Enter");
	const Key EKeys::Pause("Pause");
	const Key EKeys::Menu("Menu");

	const Key EKeys::CapsLock("CapsLock", true);
	const Key EKeys::Escape("Escape");
	const Key EKeys::SpaceBar("SpaceBar");
	const Key EKeys::PageUp("PageUp");
	const Key EKeys::PageDown("PageDown");
	const Key EKeys::End("End");
	const Key EKeys::Home("Home");

	const Key EKeys::Left("Left");
	const Key EKeys::Up("Up");
	const Key EKeys::Right("Right");
	const Key EKeys::Down("Down");

	const Key EKeys::Insert("Insert");
	const Key EKeys::Delete("Delete");

	const Key EKeys::Zero("Zero");
	const Key EKeys::One("One");
	const Key EKeys::Two("Two");
	const Key EKeys::Three("Three");
	const Key EKeys::Four("Four");
	const Key EKeys::Five("Five");
	const Key EKeys::Six("Six");
	const Key EKeys::Seven("Seven");
	const Key EKeys::Eight("Eight");
	const Key EKeys::Nine("Nine");

	const Key EKeys::A("A");
	const Key EKeys::B("B");
	const Key EKeys::C("C");
	const Key EKeys::D("D");
	const Key EKeys::E("E");
	const Key EKeys::F("F");
	const Key EKeys::G("G");
	const Key EKeys::H("H");
	const Key EKeys::I("I");
	const Key EKeys::J("J");
	const Key EKeys::K("K");
	const Key EKeys::L("L");
	const Key EKeys::M("M");
	const Key EKeys::N("N");
	const Key EKeys::O("O");
	const Key EKeys::P("P");
	const Key EKeys::Q("Q");
	const Key EKeys::R("R");
	const Key EKeys::S("S");
	const Key EKeys::T("T");
	const Key EKeys::U("U");
	const Key EKeys::V("V");
	const Key EKeys::W("W");
	const Key EKeys::X("X");
	const Key EKeys::Y("Y");
	const Key EKeys::Z("Z");

	const Key EKeys::NumPadZero("NumPadZero");
	const Key EKeys::NumPadOne("NumPadOne");
	const Key EKeys::NumPadTwo("NumPadTwo");
	const Key EKeys::NumPadThree("NumPadThree");
	const Key EKeys::NumPadFour("NumPadFour");
	const Key EKeys::NumPadFive("NumPadFive");
	const Key EKeys::NumPadSix("NumPadSix");
	const Key EKeys::NumPadSeven("NumPadSeven");
	const Key EKeys::NumPadEight("NumPadEight");
	const Key EKeys::NumPadNine("NumPadNine");
	const Key EKeys::NumPadEnter("NumPadEnter");

	const Key EKeys::Multiply("Multiply");
	const Key EKeys::Add("Add");
	const Key EKeys::Subtract("Subtract");
	const Key EKeys::Decimal("Decimal");
	const Key EKeys::Divide("Divide");

	const Key EKeys::F1("F1");
	const Key EKeys::F2("F2");
	const Key EKeys::F3("F3");
	const Key EKeys::F4("F4");
	const Key EKeys::F5("F5");
	const Key EKeys::F6("F6");
	const Key EKeys::F7("F7");
	const Key EKeys::F8("F8");
	const Key EKeys::F9("F9");
	const Key EKeys::F10("F10");
	const Key EKeys::F11("F11");
	const Key EKeys::F12("F12");

	const Key EKeys::NumLock("NumLock", true);
	const Key EKeys::PrintScreen("PrintScreen");
	const Key EKeys::ScrollLock("ScrollLock", true);

	const Key EKeys::LeftShift("LeftShift", true);
	const Key EKeys::RightShift("RightShift", true);
	const Key EKeys::LeftControl("LeftControl", true);
	const Key EKeys::RightControl("RightControl", true);
	const Key EKeys::LeftAlt("LeftAlt", true);
	const Key EKeys::RightAlt("RightAlt", true);
	const Key EKeys::LeftCommand("LeftCommand", true);
	const Key EKeys::RightCommand("RightCommand", true);

	const Key EKeys::Semicolon("Semicolon");
	const Key EKeys::Equals("Equals");
	const Key EKeys::Comma("Comma");
	const Key EKeys::Period("Period");
	const Key EKeys::Slash("Slash");
	const Key EKeys::LeftBracket("LeftBracket");
	const Key EKeys::Backslash("Backslash");
	const Key EKeys::RightBracket("RightBracket");
	const Key EKeys::Apostrophe("Apostrophe");

	const Key EKeys::Invalid("Invalid");

	const std::string EKeys::NAME_MouseCategory("Mouse");
	const std::string EKeys::NAME_KeyboardCategory("Keyboard");

}
