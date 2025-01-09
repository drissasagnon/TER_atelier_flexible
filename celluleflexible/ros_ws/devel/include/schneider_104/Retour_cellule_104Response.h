// Generated by gencpp from file schneider_104/Retour_cellule_104Response.msg
// DO NOT EDIT!


#ifndef SCHNEIDER_104_MESSAGE_RETOUR_CELLULE_104RESPONSE_H
#define SCHNEIDER_104_MESSAGE_RETOUR_CELLULE_104RESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace schneider_104
{
template <class ContainerAllocator>
struct Retour_cellule_104Response_
{
  typedef Retour_cellule_104Response_<ContainerAllocator> Type;

  Retour_cellule_104Response_()
    : ST8(false)
    , ST9(false)
    , ST10(false)
    , ST11(false)
    , ST12(false)
    , ST13(false)
    , ST14(false)
    , ST15(false)
    , ST16(false)
    , ST17(false)
    , R5D(false)
    , R6D(false)
    , R7D(false)
    , R8D(false)
    , R5G(false)
    , R6G(false)
    , R7G(false)
    , R8G(false)
    , PI3(false)
    , PI4(false)
    , PI5(false)
    , PI6(false)
    , D5(false)
    , D6(false)
    , D7(false)
    , D8(false)
    , V5(false)
    , V6(false)
    , V7(false)
    , V8(false)
    , PS8(false)
    , PS9(false)
    , PS10(false)
    , PS11(false)
    , PS12(false)
    , PS13(false)
    , PS14(false)
    , PS15(false)
    , PS16(false)
    , PS17(false)
    , D5D(false)
    , D6D(false)
    , D7D(false)
    , D8D(false)
    , D5G(false)
    , D6G(false)
    , D7G(false)
    , D8G(false)
    , CPI3(false)
    , CPI4(false)
    , CPI5(false)
    , CPI6(false)
    , CP4(false)
    , CP5(false)
    , CP6(false)
    , CP7(false)  {
    }
  Retour_cellule_104Response_(const ContainerAllocator& _alloc)
    : ST8(false)
    , ST9(false)
    , ST10(false)
    , ST11(false)
    , ST12(false)
    , ST13(false)
    , ST14(false)
    , ST15(false)
    , ST16(false)
    , ST17(false)
    , R5D(false)
    , R6D(false)
    , R7D(false)
    , R8D(false)
    , R5G(false)
    , R6G(false)
    , R7G(false)
    , R8G(false)
    , PI3(false)
    , PI4(false)
    , PI5(false)
    , PI6(false)
    , D5(false)
    , D6(false)
    , D7(false)
    , D8(false)
    , V5(false)
    , V6(false)
    , V7(false)
    , V8(false)
    , PS8(false)
    , PS9(false)
    , PS10(false)
    , PS11(false)
    , PS12(false)
    , PS13(false)
    , PS14(false)
    , PS15(false)
    , PS16(false)
    , PS17(false)
    , D5D(false)
    , D6D(false)
    , D7D(false)
    , D8D(false)
    , D5G(false)
    , D6G(false)
    , D7G(false)
    , D8G(false)
    , CPI3(false)
    , CPI4(false)
    , CPI5(false)
    , CPI6(false)
    , CP4(false)
    , CP5(false)
    , CP6(false)
    , CP7(false)  {
  (void)_alloc;
    }



   typedef uint8_t _ST8_type;
  _ST8_type ST8;

   typedef uint8_t _ST9_type;
  _ST9_type ST9;

   typedef uint8_t _ST10_type;
  _ST10_type ST10;

   typedef uint8_t _ST11_type;
  _ST11_type ST11;

   typedef uint8_t _ST12_type;
  _ST12_type ST12;

   typedef uint8_t _ST13_type;
  _ST13_type ST13;

   typedef uint8_t _ST14_type;
  _ST14_type ST14;

   typedef uint8_t _ST15_type;
  _ST15_type ST15;

   typedef uint8_t _ST16_type;
  _ST16_type ST16;

   typedef uint8_t _ST17_type;
  _ST17_type ST17;

   typedef uint8_t _R5D_type;
  _R5D_type R5D;

   typedef uint8_t _R6D_type;
  _R6D_type R6D;

   typedef uint8_t _R7D_type;
  _R7D_type R7D;

   typedef uint8_t _R8D_type;
  _R8D_type R8D;

   typedef uint8_t _R5G_type;
  _R5G_type R5G;

   typedef uint8_t _R6G_type;
  _R6G_type R6G;

   typedef uint8_t _R7G_type;
  _R7G_type R7G;

   typedef uint8_t _R8G_type;
  _R8G_type R8G;

   typedef uint8_t _PI3_type;
  _PI3_type PI3;

   typedef uint8_t _PI4_type;
  _PI4_type PI4;

   typedef uint8_t _PI5_type;
  _PI5_type PI5;

   typedef uint8_t _PI6_type;
  _PI6_type PI6;

   typedef uint8_t _D5_type;
  _D5_type D5;

   typedef uint8_t _D6_type;
  _D6_type D6;

   typedef uint8_t _D7_type;
  _D7_type D7;

   typedef uint8_t _D8_type;
  _D8_type D8;

   typedef uint8_t _V5_type;
  _V5_type V5;

   typedef uint8_t _V6_type;
  _V6_type V6;

   typedef uint8_t _V7_type;
  _V7_type V7;

   typedef uint8_t _V8_type;
  _V8_type V8;

   typedef uint8_t _PS8_type;
  _PS8_type PS8;

   typedef uint8_t _PS9_type;
  _PS9_type PS9;

   typedef uint8_t _PS10_type;
  _PS10_type PS10;

   typedef uint8_t _PS11_type;
  _PS11_type PS11;

   typedef uint8_t _PS12_type;
  _PS12_type PS12;

   typedef uint8_t _PS13_type;
  _PS13_type PS13;

   typedef uint8_t _PS14_type;
  _PS14_type PS14;

   typedef uint8_t _PS15_type;
  _PS15_type PS15;

   typedef uint8_t _PS16_type;
  _PS16_type PS16;

   typedef uint8_t _PS17_type;
  _PS17_type PS17;

   typedef uint8_t _D5D_type;
  _D5D_type D5D;

   typedef uint8_t _D6D_type;
  _D6D_type D6D;

   typedef uint8_t _D7D_type;
  _D7D_type D7D;

   typedef uint8_t _D8D_type;
  _D8D_type D8D;

   typedef uint8_t _D5G_type;
  _D5G_type D5G;

   typedef uint8_t _D6G_type;
  _D6G_type D6G;

   typedef uint8_t _D7G_type;
  _D7G_type D7G;

   typedef uint8_t _D8G_type;
  _D8G_type D8G;

   typedef uint8_t _CPI3_type;
  _CPI3_type CPI3;

   typedef uint8_t _CPI4_type;
  _CPI4_type CPI4;

   typedef uint8_t _CPI5_type;
  _CPI5_type CPI5;

   typedef uint8_t _CPI6_type;
  _CPI6_type CPI6;

   typedef uint8_t _CP4_type;
  _CP4_type CP4;

   typedef uint8_t _CP5_type;
  _CP5_type CP5;

   typedef uint8_t _CP6_type;
  _CP6_type CP6;

   typedef uint8_t _CP7_type;
  _CP7_type CP7;





  typedef boost::shared_ptr< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> const> ConstPtr;

}; // struct Retour_cellule_104Response_

typedef ::schneider_104::Retour_cellule_104Response_<std::allocator<void> > Retour_cellule_104Response;

typedef boost::shared_ptr< ::schneider_104::Retour_cellule_104Response > Retour_cellule_104ResponsePtr;
typedef boost::shared_ptr< ::schneider_104::Retour_cellule_104Response const> Retour_cellule_104ResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::schneider_104::Retour_cellule_104Response_<ContainerAllocator1> & lhs, const ::schneider_104::Retour_cellule_104Response_<ContainerAllocator2> & rhs)
{
  return lhs.ST8 == rhs.ST8 &&
    lhs.ST9 == rhs.ST9 &&
    lhs.ST10 == rhs.ST10 &&
    lhs.ST11 == rhs.ST11 &&
    lhs.ST12 == rhs.ST12 &&
    lhs.ST13 == rhs.ST13 &&
    lhs.ST14 == rhs.ST14 &&
    lhs.ST15 == rhs.ST15 &&
    lhs.ST16 == rhs.ST16 &&
    lhs.ST17 == rhs.ST17 &&
    lhs.R5D == rhs.R5D &&
    lhs.R6D == rhs.R6D &&
    lhs.R7D == rhs.R7D &&
    lhs.R8D == rhs.R8D &&
    lhs.R5G == rhs.R5G &&
    lhs.R6G == rhs.R6G &&
    lhs.R7G == rhs.R7G &&
    lhs.R8G == rhs.R8G &&
    lhs.PI3 == rhs.PI3 &&
    lhs.PI4 == rhs.PI4 &&
    lhs.PI5 == rhs.PI5 &&
    lhs.PI6 == rhs.PI6 &&
    lhs.D5 == rhs.D5 &&
    lhs.D6 == rhs.D6 &&
    lhs.D7 == rhs.D7 &&
    lhs.D8 == rhs.D8 &&
    lhs.V5 == rhs.V5 &&
    lhs.V6 == rhs.V6 &&
    lhs.V7 == rhs.V7 &&
    lhs.V8 == rhs.V8 &&
    lhs.PS8 == rhs.PS8 &&
    lhs.PS9 == rhs.PS9 &&
    lhs.PS10 == rhs.PS10 &&
    lhs.PS11 == rhs.PS11 &&
    lhs.PS12 == rhs.PS12 &&
    lhs.PS13 == rhs.PS13 &&
    lhs.PS14 == rhs.PS14 &&
    lhs.PS15 == rhs.PS15 &&
    lhs.PS16 == rhs.PS16 &&
    lhs.PS17 == rhs.PS17 &&
    lhs.D5D == rhs.D5D &&
    lhs.D6D == rhs.D6D &&
    lhs.D7D == rhs.D7D &&
    lhs.D8D == rhs.D8D &&
    lhs.D5G == rhs.D5G &&
    lhs.D6G == rhs.D6G &&
    lhs.D7G == rhs.D7G &&
    lhs.D8G == rhs.D8G &&
    lhs.CPI3 == rhs.CPI3 &&
    lhs.CPI4 == rhs.CPI4 &&
    lhs.CPI5 == rhs.CPI5 &&
    lhs.CPI6 == rhs.CPI6 &&
    lhs.CP4 == rhs.CP4 &&
    lhs.CP5 == rhs.CP5 &&
    lhs.CP6 == rhs.CP6 &&
    lhs.CP7 == rhs.CP7;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::schneider_104::Retour_cellule_104Response_<ContainerAllocator1> & lhs, const ::schneider_104::Retour_cellule_104Response_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace schneider_104

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e2f36819397689b3da7a9f133a5a1cfa";
  }

  static const char* value(const ::schneider_104::Retour_cellule_104Response_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe2f36819397689b3ULL;
  static const uint64_t static_value2 = 0xda7a9f133a5a1cfaULL;
};

template<class ContainerAllocator>
struct DataType< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> >
{
  static const char* value()
  {
    return "schneider_104/Retour_cellule_104Response";
  }

  static const char* value(const ::schneider_104::Retour_cellule_104Response_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool ST8\n"
"bool ST9\n"
"bool ST10\n"
"bool ST11\n"
"bool ST12\n"
"bool ST13\n"
"bool ST14\n"
"bool ST15\n"
"bool ST16\n"
"bool ST17\n"
"bool R5D\n"
"bool R6D\n"
"bool R7D\n"
"bool R8D\n"
"bool R5G\n"
"bool R6G\n"
"bool R7G\n"
"bool R8G\n"
"bool PI3\n"
"bool PI4\n"
"bool PI5\n"
"bool PI6\n"
"bool D5\n"
"bool D6\n"
"bool D7\n"
"bool D8\n"
"bool V5\n"
"bool V6\n"
"bool V7\n"
"bool V8\n"
"bool PS8\n"
"bool PS9\n"
"bool PS10\n"
"bool PS11\n"
"bool PS12\n"
"bool PS13\n"
"bool PS14\n"
"bool PS15\n"
"bool PS16\n"
"bool PS17\n"
"bool D5D\n"
"bool D6D\n"
"bool D7D\n"
"bool D8D\n"
"bool D5G\n"
"bool D6G\n"
"bool D7G\n"
"bool D8G\n"
"bool CPI3\n"
"bool CPI4\n"
"bool CPI5\n"
"bool CPI6\n"
"bool CP4\n"
"bool CP5\n"
"bool CP6\n"
"bool CP7\n"
"\n"
;
  }

  static const char* value(const ::schneider_104::Retour_cellule_104Response_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ST8);
      stream.next(m.ST9);
      stream.next(m.ST10);
      stream.next(m.ST11);
      stream.next(m.ST12);
      stream.next(m.ST13);
      stream.next(m.ST14);
      stream.next(m.ST15);
      stream.next(m.ST16);
      stream.next(m.ST17);
      stream.next(m.R5D);
      stream.next(m.R6D);
      stream.next(m.R7D);
      stream.next(m.R8D);
      stream.next(m.R5G);
      stream.next(m.R6G);
      stream.next(m.R7G);
      stream.next(m.R8G);
      stream.next(m.PI3);
      stream.next(m.PI4);
      stream.next(m.PI5);
      stream.next(m.PI6);
      stream.next(m.D5);
      stream.next(m.D6);
      stream.next(m.D7);
      stream.next(m.D8);
      stream.next(m.V5);
      stream.next(m.V6);
      stream.next(m.V7);
      stream.next(m.V8);
      stream.next(m.PS8);
      stream.next(m.PS9);
      stream.next(m.PS10);
      stream.next(m.PS11);
      stream.next(m.PS12);
      stream.next(m.PS13);
      stream.next(m.PS14);
      stream.next(m.PS15);
      stream.next(m.PS16);
      stream.next(m.PS17);
      stream.next(m.D5D);
      stream.next(m.D6D);
      stream.next(m.D7D);
      stream.next(m.D8D);
      stream.next(m.D5G);
      stream.next(m.D6G);
      stream.next(m.D7G);
      stream.next(m.D8G);
      stream.next(m.CPI3);
      stream.next(m.CPI4);
      stream.next(m.CPI5);
      stream.next(m.CPI6);
      stream.next(m.CP4);
      stream.next(m.CP5);
      stream.next(m.CP6);
      stream.next(m.CP7);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Retour_cellule_104Response_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::schneider_104::Retour_cellule_104Response_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::schneider_104::Retour_cellule_104Response_<ContainerAllocator>& v)
  {
    s << indent << "ST8: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ST8);
    s << indent << "ST9: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ST9);
    s << indent << "ST10: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ST10);
    s << indent << "ST11: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ST11);
    s << indent << "ST12: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ST12);
    s << indent << "ST13: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ST13);
    s << indent << "ST14: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ST14);
    s << indent << "ST15: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ST15);
    s << indent << "ST16: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ST16);
    s << indent << "ST17: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ST17);
    s << indent << "R5D: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.R5D);
    s << indent << "R6D: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.R6D);
    s << indent << "R7D: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.R7D);
    s << indent << "R8D: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.R8D);
    s << indent << "R5G: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.R5G);
    s << indent << "R6G: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.R6G);
    s << indent << "R7G: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.R7G);
    s << indent << "R8G: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.R8G);
    s << indent << "PI3: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PI3);
    s << indent << "PI4: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PI4);
    s << indent << "PI5: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PI5);
    s << indent << "PI6: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PI6);
    s << indent << "D5: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D5);
    s << indent << "D6: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D6);
    s << indent << "D7: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D7);
    s << indent << "D8: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D8);
    s << indent << "V5: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.V5);
    s << indent << "V6: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.V6);
    s << indent << "V7: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.V7);
    s << indent << "V8: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.V8);
    s << indent << "PS8: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PS8);
    s << indent << "PS9: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PS9);
    s << indent << "PS10: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PS10);
    s << indent << "PS11: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PS11);
    s << indent << "PS12: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PS12);
    s << indent << "PS13: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PS13);
    s << indent << "PS14: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PS14);
    s << indent << "PS15: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PS15);
    s << indent << "PS16: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PS16);
    s << indent << "PS17: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.PS17);
    s << indent << "D5D: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D5D);
    s << indent << "D6D: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D6D);
    s << indent << "D7D: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D7D);
    s << indent << "D8D: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D8D);
    s << indent << "D5G: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D5G);
    s << indent << "D6G: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D6G);
    s << indent << "D7G: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D7G);
    s << indent << "D8G: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.D8G);
    s << indent << "CPI3: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.CPI3);
    s << indent << "CPI4: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.CPI4);
    s << indent << "CPI5: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.CPI5);
    s << indent << "CPI6: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.CPI6);
    s << indent << "CP4: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.CP4);
    s << indent << "CP5: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.CP5);
    s << indent << "CP6: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.CP6);
    s << indent << "CP7: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.CP7);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SCHNEIDER_104_MESSAGE_RETOUR_CELLULE_104RESPONSE_H
