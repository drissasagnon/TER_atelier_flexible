// Generated by gencpp from file aiguillages/Actionneurs.msg
// DO NOT EDIT!


#ifndef AIGUILLAGES_MESSAGE_ACTIONNEURS_H
#define AIGUILLAGES_MESSAGE_ACTIONNEURS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace aiguillages
{
template <class ContainerAllocator>
struct Actionneurs_
{
  typedef Actionneurs_<ContainerAllocator> Type;

  Actionneurs_()
    : actionneurs(0)  {
    }
  Actionneurs_(const ContainerAllocator& _alloc)
    : actionneurs(0)  {
  (void)_alloc;
    }



   typedef int64_t _actionneurs_type;
  _actionneurs_type actionneurs;





  typedef boost::shared_ptr< ::aiguillages::Actionneurs_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::aiguillages::Actionneurs_<ContainerAllocator> const> ConstPtr;

}; // struct Actionneurs_

typedef ::aiguillages::Actionneurs_<std::allocator<void> > Actionneurs;

typedef boost::shared_ptr< ::aiguillages::Actionneurs > ActionneursPtr;
typedef boost::shared_ptr< ::aiguillages::Actionneurs const> ActionneursConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::aiguillages::Actionneurs_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::aiguillages::Actionneurs_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::aiguillages::Actionneurs_<ContainerAllocator1> & lhs, const ::aiguillages::Actionneurs_<ContainerAllocator2> & rhs)
{
  return lhs.actionneurs == rhs.actionneurs;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::aiguillages::Actionneurs_<ContainerAllocator1> & lhs, const ::aiguillages::Actionneurs_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace aiguillages

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::aiguillages::Actionneurs_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::aiguillages::Actionneurs_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::aiguillages::Actionneurs_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::aiguillages::Actionneurs_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::aiguillages::Actionneurs_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::aiguillages::Actionneurs_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::aiguillages::Actionneurs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1a79d0b13aebfb5d0450ddf675b8fc68";
  }

  static const char* value(const ::aiguillages::Actionneurs_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1a79d0b13aebfb5dULL;
  static const uint64_t static_value2 = 0x0450ddf675b8fc68ULL;
};

template<class ContainerAllocator>
struct DataType< ::aiguillages::Actionneurs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aiguillages/Actionneurs";
  }

  static const char* value(const ::aiguillages::Actionneurs_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::aiguillages::Actionneurs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 actionneurs\n"
"\n"
"\n"
;
  }

  static const char* value(const ::aiguillages::Actionneurs_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::aiguillages::Actionneurs_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.actionneurs);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Actionneurs_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::aiguillages::Actionneurs_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::aiguillages::Actionneurs_<ContainerAllocator>& v)
  {
    s << indent << "actionneurs: ";
    Printer<int64_t>::stream(s, indent + "  ", v.actionneurs);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AIGUILLAGES_MESSAGE_ACTIONNEURS_H
