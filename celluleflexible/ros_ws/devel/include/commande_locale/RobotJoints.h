// Generated by gencpp from file commande_locale/RobotJoints.msg
// DO NOT EDIT!


#ifndef COMMANDE_LOCALE_MESSAGE_ROBOTJOINTS_H
#define COMMANDE_LOCALE_MESSAGE_ROBOTJOINTS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace commande_locale
{
template <class ContainerAllocator>
struct RobotJoints_
{
  typedef RobotJoints_<ContainerAllocator> Type;

  RobotJoints_()
    : joint1(0)
    , joint2(0)
    , joint3(0)
    , joint4(0)
    , joint5(0)
    , joint6(0)
    , joint7(0)
    , num_robot(0)  {
    }
  RobotJoints_(const ContainerAllocator& _alloc)
    : joint1(0)
    , joint2(0)
    , joint3(0)
    , joint4(0)
    , joint5(0)
    , joint6(0)
    , joint7(0)
    , num_robot(0)  {
  (void)_alloc;
    }



   typedef int32_t _joint1_type;
  _joint1_type joint1;

   typedef int32_t _joint2_type;
  _joint2_type joint2;

   typedef int32_t _joint3_type;
  _joint3_type joint3;

   typedef int32_t _joint4_type;
  _joint4_type joint4;

   typedef int32_t _joint5_type;
  _joint5_type joint5;

   typedef int32_t _joint6_type;
  _joint6_type joint6;

   typedef int32_t _joint7_type;
  _joint7_type joint7;

   typedef int32_t _num_robot_type;
  _num_robot_type num_robot;





  typedef boost::shared_ptr< ::commande_locale::RobotJoints_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::commande_locale::RobotJoints_<ContainerAllocator> const> ConstPtr;

}; // struct RobotJoints_

typedef ::commande_locale::RobotJoints_<std::allocator<void> > RobotJoints;

typedef boost::shared_ptr< ::commande_locale::RobotJoints > RobotJointsPtr;
typedef boost::shared_ptr< ::commande_locale::RobotJoints const> RobotJointsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::commande_locale::RobotJoints_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::commande_locale::RobotJoints_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::commande_locale::RobotJoints_<ContainerAllocator1> & lhs, const ::commande_locale::RobotJoints_<ContainerAllocator2> & rhs)
{
  return lhs.joint1 == rhs.joint1 &&
    lhs.joint2 == rhs.joint2 &&
    lhs.joint3 == rhs.joint3 &&
    lhs.joint4 == rhs.joint4 &&
    lhs.joint5 == rhs.joint5 &&
    lhs.joint6 == rhs.joint6 &&
    lhs.joint7 == rhs.joint7 &&
    lhs.num_robot == rhs.num_robot;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::commande_locale::RobotJoints_<ContainerAllocator1> & lhs, const ::commande_locale::RobotJoints_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace commande_locale

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::commande_locale::RobotJoints_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::commande_locale::RobotJoints_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::commande_locale::RobotJoints_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::commande_locale::RobotJoints_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::commande_locale::RobotJoints_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::commande_locale::RobotJoints_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::commande_locale::RobotJoints_<ContainerAllocator> >
{
  static const char* value()
  {
    return "83d02ab5b13f8f1d23146613b3ae26a8";
  }

  static const char* value(const ::commande_locale::RobotJoints_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x83d02ab5b13f8f1dULL;
  static const uint64_t static_value2 = 0x23146613b3ae26a8ULL;
};

template<class ContainerAllocator>
struct DataType< ::commande_locale::RobotJoints_<ContainerAllocator> >
{
  static const char* value()
  {
    return "commande_locale/RobotJoints";
  }

  static const char* value(const ::commande_locale::RobotJoints_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::commande_locale::RobotJoints_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 joint1\n"
"int32 joint2\n"
"int32 joint3\n"
"int32 joint4\n"
"int32 joint5\n"
"int32 joint6\n"
"int32 joint7\n"
"int32 num_robot\n"
;
  }

  static const char* value(const ::commande_locale::RobotJoints_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::commande_locale::RobotJoints_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.joint1);
      stream.next(m.joint2);
      stream.next(m.joint3);
      stream.next(m.joint4);
      stream.next(m.joint5);
      stream.next(m.joint6);
      stream.next(m.joint7);
      stream.next(m.num_robot);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RobotJoints_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::commande_locale::RobotJoints_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::commande_locale::RobotJoints_<ContainerAllocator>& v)
  {
    s << indent << "joint1: ";
    Printer<int32_t>::stream(s, indent + "  ", v.joint1);
    s << indent << "joint2: ";
    Printer<int32_t>::stream(s, indent + "  ", v.joint2);
    s << indent << "joint3: ";
    Printer<int32_t>::stream(s, indent + "  ", v.joint3);
    s << indent << "joint4: ";
    Printer<int32_t>::stream(s, indent + "  ", v.joint4);
    s << indent << "joint5: ";
    Printer<int32_t>::stream(s, indent + "  ", v.joint5);
    s << indent << "joint6: ";
    Printer<int32_t>::stream(s, indent + "  ", v.joint6);
    s << indent << "joint7: ";
    Printer<int32_t>::stream(s, indent + "  ", v.joint7);
    s << indent << "num_robot: ";
    Printer<int32_t>::stream(s, indent + "  ", v.num_robot);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COMMANDE_LOCALE_MESSAGE_ROBOTJOINTS_H
