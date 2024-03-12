#pragma once

namespace Lamp
{
	struct Position2D
	{
		double X, Y;
		
		Position2D()
			:X{0}, Y{0}
		{ }
		Position2D(double xPos, double yPos)
			:X{xPos}, Y{yPos}
		{
		}
		Position2D(const Position2D& other)
			:X{other.X}, Y{other.Y}
		{ }

		friend bool operator==(const Position2D& l, const Position2D& r)
		{
			return (l.X == r.X) && (l.Y == r.Y);
		}
		friend bool operator!=(const Position2D& l, const Position2D& r)
		{
			return !(l == r);
		}
		friend Position2D operator+(const Position2D& l, const Position2D& r)
		{
			return {l.X + r.X, l.Y + r.Y};
		}
		friend Position2D operator-(const Position2D& l, const Position2D& r)
		{
			return {l.X - r.X, l.Y - r.Y};
		}
	};
}
