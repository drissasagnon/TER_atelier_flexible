// Generated by gencpp from file shuttles/shuttle_idResponse.msg
// DO NOT EDIT!


#ifndef SHUTTLES_MESSAGE_SHUTTLE_IDRESPONSE_H
#define SHUTTLES_MESSAGE_SHUTTLE_IDRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace shuttles
{
template <class ContainerAllocator>
struct shuttle_idResponse_
{
  typedef shuttle_idResponse_<ContainerAllocator> Type;

  shuttle_idResponse_()
    : IdShuttle(0)  {
    }
  shuttle_idResponse_(const ContainerAllocator& _alloc)
    : IdShuttle(0)  {
  (void)_alloc;
    }



   typedef int32_t _IdShuttle_type;
  _IdShuttle_type IdShuttle;





  typedef boost::shared_ptr< ::shuttles::shuttle_idResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::shuttles::shuttle_idResponse_<ContainerAllocator> const> ConstPtr;

}; // struct shuttle_idResponse_

typedef ::shuttles::shuttle_idResponse_<std::allocator<void> > shuttle_idResponse;

typedef boost::shared_ptr< ::shuttles::shuttle_idResponse > shuttle_idResponsePtr;
typedef boost::shared_ptr< ::shuttles::shuttle_idResponse const> shuttle_idResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::shuttles::shuttle_idResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::shuttles::shuttle_idResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::shuttles::shuttle_idResponse_<ContainerAllocator1> & lhs, const ::shuttles::shuttle_idResponse_<ContainerAllocator2> & rhs)
{
  return lhs.IdShuttle == rhs.IdShuttle;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::shuttles::shuttle_idResponse_<ContainerAllocator1> & lhs, const ::shuttles::shuttle_idResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace shuttles

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::shuttles::shuttle_idResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shuttles::shuttle_idResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::shuttles::shuttle_idResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::shuttles::shuttle_idResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shuttles::shuttle_idResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shuttles::shuttle_idResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::shuttles::shuttle_idResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "39f3cc90c3f781e09c842cf3e85b7aa9";
  }

  static const char* value(const ::shuttles::shuttle_idResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x39f3cc90c3f781e0ULL;
  static const uint64_t static_value2 = 0x9c842cf3e85b7aa9ULL;
};

template<class ContainerAllocator>
struct DataType< ::shuttles::shuttle_idResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "shuttles/shuttle_idResponse";
  }

  static const char* value(const ::shuttles::shuttle_idResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::shuttles::shuttle_idResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 IdShuttle\n"
"\n"
;
  }

  static const char* value(const ::shuttles::shuttle_idResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::shuttles::shuttle_idResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.IdShuttle);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct shuttle_idResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::shuttles::shuttle_idResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::shuttles::shuttle_idResponse_<ContainerAllocator>& v)
  {
    s << indent << "IdShuttle: ";
    Printer<int32_t>::stream(s, indent + "  ", v.IdShuttle);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SHUTTLES_MESSAGE_SHUTTLE_IDRESPONSE_H