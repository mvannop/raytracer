#include "chrono.hh"

chrono::chrono(bool s)
{
  if (s)
    start();
}

void chrono::start()
{
  s_ = boost::posix_time::microsec_clock::local_time();
}

void chrono::end()
{
  e_ = boost::posix_time::microsec_clock::local_time();
}

unsigned long int chrono::duration() const
{
  return (e_ - s_).total_microseconds();
}

unsigned long int chrono::cur_duration() const
{
  return (boost::posix_time::microsec_clock::local_time() - s_).total_microseconds();
}
