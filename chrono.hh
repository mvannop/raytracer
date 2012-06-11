#ifndef COMMON_CHRONO_HH
# define COMMON_CHRONO_HH

# include "boost/date_time/posix_time/posix_time_types.hpp"

class chrono
{
  public:

    chrono(bool start = true);

    void start();
    void end();

    // In microseconds.
    unsigned long int duration() const;

    unsigned long int cur_duration() const;

  private:

    boost::posix_time::ptime s_;
    boost::posix_time::ptime e_;
};

#endif // !COMMON_CHRONO_HH
