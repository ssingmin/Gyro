// Generated by gencpp from file Gyro/Gyro_msg.msg
// DO NOT EDIT!


#ifndef GYRO_MESSAGE_GYRO_MSG_H
#define GYRO_MESSAGE_GYRO_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace Gyro
{
template <class ContainerAllocator>
struct Gyro_msg_
{
  typedef Gyro_msg_<ContainerAllocator> Type;

  Gyro_msg_()
    : data(0)  {
    }
  Gyro_msg_(const ContainerAllocator& _alloc)
    : data(0)  {
  (void)_alloc;
    }



   typedef int32_t _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::Gyro::Gyro_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::Gyro::Gyro_msg_<ContainerAllocator> const> ConstPtr;

}; // struct Gyro_msg_

typedef ::Gyro::Gyro_msg_<std::allocator<void> > Gyro_msg;

typedef boost::shared_ptr< ::Gyro::Gyro_msg > Gyro_msgPtr;
typedef boost::shared_ptr< ::Gyro::Gyro_msg const> Gyro_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::Gyro::Gyro_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::Gyro::Gyro_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::Gyro::Gyro_msg_<ContainerAllocator1> & lhs, const ::Gyro::Gyro_msg_<ContainerAllocator2> & rhs)
{
  return lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::Gyro::Gyro_msg_<ContainerAllocator1> & lhs, const ::Gyro::Gyro_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace Gyro

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::Gyro::Gyro_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::Gyro::Gyro_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::Gyro::Gyro_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::Gyro::Gyro_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::Gyro::Gyro_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::Gyro::Gyro_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::Gyro::Gyro_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "da5909fbe378aeaf85e547e830cc1bb7";
  }

  static const char* value(const ::Gyro::Gyro_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xda5909fbe378aeafULL;
  static const uint64_t static_value2 = 0x85e547e830cc1bb7ULL;
};

template<class ContainerAllocator>
struct DataType< ::Gyro::Gyro_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Gyro/Gyro_msg";
  }

  static const char* value(const ::Gyro::Gyro_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::Gyro::Gyro_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 data\n"
;
  }

  static const char* value(const ::Gyro::Gyro_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::Gyro::Gyro_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Gyro_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::Gyro::Gyro_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::Gyro::Gyro_msg_<ContainerAllocator>& v)
  {
    s << indent << "data: ";
    Printer<int32_t>::stream(s, indent + "  ", v.data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GYRO_MESSAGE_GYRO_MSG_H
