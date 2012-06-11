
inline coordinate& coordinate::operator-=(const coordinate& rhs)
{
  x_ -= rhs.x_;
  y_ -= rhs.y_;
  z_ -= rhs.z_;

  return *this;
}

inline coordinate& coordinate::operator+=(const coordinate& rhs)
{
  x_ += rhs.x_;
  y_ += rhs.y_;
  z_ += rhs.z_;

  return *this;
}

inline coordinate& coordinate::operator*=(double rhs)
{
  x_ *= rhs;
  y_ *= rhs;
  z_ *= rhs;

  return *this;
}

inline coordinate& coordinate::operator/=(double rhs)
{
  x_ /= rhs;
  y_ /= rhs;
  z_ /= rhs;

  return *this;
}

inline coordinate operator-(const coordinate& lhs, const coordinate& rhs)
{
  coordinate res(lhs);
  res -= rhs;
  return res;
}

inline coordinate operator+(const coordinate& lhs, const coordinate& rhs)
{
  coordinate res(lhs);
  res += rhs;
  return res;
}

inline coordinate operator*(double lhs, const coordinate& rhs)
{
  coordinate res(rhs);
  res *= lhs;
  return res;
}

inline coordinate operator/(const coordinate& lhs, double rhs)
{
  coordinate res(lhs);
  res /= rhs;
  return res;
}
