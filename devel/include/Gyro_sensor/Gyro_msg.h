// Generated by gencpp from file Gyro_sensor/Gyro_msg.msg
// DO NOT EDIT!


#ifndef GYRO_SENSOR_MESSAGE_GYRO_MSG_H
#define GYRO_SENSOR_MESSAGE_GYRO_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace Gyro_sensor
{
template <class ContainerAllocator>
struct Gyro_msg_
{
  typedef Gyro_msg_<ContainerAllocator> Type;

  Gyro_msg_()
    : a_x(0.0)
    , a_y(0.0)
    , a_z(0.0)
    , w_x(0.0)
    , w_y(0.0)
    , w_z(0.0)
    , an_x(0.0)
    , an_y(0.0)
    , an_z(0.0)  {
    }
  Gyro_msg_(const ContainerAllocator& _alloc)
    : a_x(0.0)
    , a_y(0.0)
    , a_z(0.0)
    , w_x(0.0)
    , w_y(0.0)
    , w_z(0.0)
    , an_x(0.0)
    , an_y(0.0)
    , an_z(0.0)  {
  (void)_alloc;
    }



   typedef float _a_x_type;
  _a_x_type a_x;

   typedef float _a_y_type;
  _a_y_type a_y;

   typedef float _a_z_type;
  _a_z_type a_z;

   typedef float _w_x_type;
  _w_x_type w_x;

   typedef float _w_y_type;
  _w_y_type w_y;

   typedef float _w_z_type;
  _w_z_type w_z;

   typedef float _an_x_type;
  _an_x_type an_x;

   typedef float _an_y_type;
  _an_y_type an_y;

   typedef float _an_z_type;
  _an_z_type an_z;





  typedef boost::shared_ptr< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> const> ConstPtr;

}; // struct Gyro_msg_

typedef ::Gyro_sensor::Gyro_msg_<std::allocator<void> > Gyro_msg;

typedef boost::shared_ptr< ::Gyro_sensor::Gyro_msg > Gyro_msgPtr;
typedef boost::shared_ptr< ::Gyro_sensor::Gyro_msg const> Gyro_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::Gyro_sensor::Gyro_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::Gyro_sensor::Gyro_msg_<ContainerAllocator1> & lhs, const ::Gyro_sensor::Gyro_msg_<ContainerAllocator2> & rhs)
{
  return lhs.a_x == rhs.a_x &&
    lhs.a_y == rhs.a_y &&
    lhs.a_z == rhs.a_z &&
    lhs.w_x == rhs.w_x &&
    lhs.w_y == rhs.w_y &&
    lhs.w_z == rhs.w_z &&
    lhs.an_x == rhs.an_x &&
    lhs.an_y == rhs.an_y &&
    lhs.an_z == rhs.an_z;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::Gyro_sensor::Gyro_msg_<ContainerAllocator1> & lhs, const ::Gyro_sensor::Gyro_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace Gyro_sensor

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fb2bb114d1e350ea2deb434716fc40d9";
  }

  static const char* value(const ::Gyro_sensor::Gyro_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfb2bb114d1e350eaULL;
  static const uint64_t static_value2 = 0x2deb434716fc40d9ULL;
};

template<class ContainerAllocator>
struct DataType< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Gyro_sensor/Gyro_msg";
  }

  static const char* value(const ::Gyro_sensor::Gyro_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 a_x\n"
"float32 a_y\n"
"float32 a_z\n"
"\n"
"float32 w_x\n"
"float32 w_y\n"
"float32 w_z\n"
"\n"
"float32 an_x\n"
"float32 an_y\n"
"float32 an_z\n"
;
  }

  static const char* value(const ::Gyro_sensor::Gyro_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.a_x);
      stream.next(m.a_y);
      stream.next(m.a_z);
      stream.next(m.w_x);
      stream.next(m.w_y);
      stream.next(m.w_z);
      stream.next(m.an_x);
      stream.next(m.an_y);
      stream.next(m.an_z);
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
struct Printer< ::Gyro_sensor::Gyro_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::Gyro_sensor::Gyro_msg_<ContainerAllocator>& v)
  {
    s << indent << "a_x: ";
    Printer<float>::stream(s, indent + "  ", v.a_x);
    s << indent << "a_y: ";
    Printer<float>::stream(s, indent + "  ", v.a_y);
    s << indent << "a_z: ";
    Printer<float>::stream(s, indent + "  ", v.a_z);
    s << indent << "w_x: ";
    Printer<float>::stream(s, indent + "  ", v.w_x);
    s << indent << "w_y: ";
    Printer<float>::stream(s, indent + "  ", v.w_y);
    s << indent << "w_z: ";
    Printer<float>::stream(s, indent + "  ", v.w_z);
    s << indent << "an_x: ";
    Printer<float>::stream(s, indent + "  ", v.an_x);
    s << indent << "an_y: ";
    Printer<float>::stream(s, indent + "  ", v.an_y);
    s << indent << "an_z: ";
    Printer<float>::stream(s, indent + "  ", v.an_z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GYRO_SENSOR_MESSAGE_GYRO_MSG_H