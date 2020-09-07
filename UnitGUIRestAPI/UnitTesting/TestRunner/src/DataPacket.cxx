// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file DataPacket.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "DataPacket.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

/*!
 * @brief Default constructor.
 */
DataPacket::DataPacket()
{
    // m_index com.eprosima.idl.parser.typecode.PrimitiveTypeCode@267ef4
    m_index = 0;
    // m_message com.eprosima.idl.parser.typecode.StringTypeCode@15eaaf1
    m_message ="";

}

/*!
 * @brief Default destructor.
 */
DataPacket::~DataPacket()
{
}

/*!
 * @brief Copy constructor.
 * @param x Reference to the object DataPacket that will be copied.
 */
DataPacket::DataPacket(const DataPacket &x)
{
    m_index = x.m_index;
    m_message = x.m_message;
}

/*!
 * @brief Move constructor.
 * @param x Reference to the object DataPacket that will be copied.
 */
DataPacket::DataPacket(DataPacket &&x)
{
    m_index = x.m_index;
    m_message = std::move(x.m_message);
}

/*!
 * @brief Copy assignment.
 * @param x Reference to the object DataPacket that will be copied.
 */
DataPacket& DataPacket::operator=(const DataPacket &x)
{

    m_index = x.m_index;
    m_message = x.m_message;

    return *this;
}

/*!
 * @brief Move assignment.
 * @param x Reference to the object DataPacket that will be copied.
 */
DataPacket& DataPacket::operator=(DataPacket &&x)
{

    m_index = x.m_index;
    m_message = std::move(x.m_message);

    return *this;
}

/*!
 * @brief This function returns the maximum serialized size of an object
 * depending on the buffer alignment.
 * @param current_alignment Buffer alignment.
 * @return Maximum serialized size.
 */
size_t DataPacket::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;


    return current_alignment - initial_alignment;
}

/*!
 * @brief This function returns the serialized size of a data depending on the buffer alignment.
 * @param data Data which is calculated its serialized size.
 * @param current_alignment Buffer alignment.
 * @return Serialized size.
 */
size_t DataPacket::getCdrSerializedSize(const DataPacket& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.message().size() + 1;


    return current_alignment - initial_alignment;
}

/*!
 * @brief This function serializes an object using CDR serialization.
 * @param cdr CDR serialization object.
 */
void DataPacket::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_index;
    scdr << m_message;
}

/*!
 * @brief This function deserializes an object using CDR serialization.
 * @param cdr CDR serialization object.
 */
void DataPacket::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_index;
    dcdr >> m_message;
}

/*!
 * @brief This function sets a value in member index
 * @param _index New value for member index
 */
void DataPacket::index(uint32_t _index)
{
m_index = _index;
}

/*!
 * @brief This function returns the value of member index
 * @return Value of member index
 */
uint32_t DataPacket::index() const
{
    return m_index;
}

/*!
 * @brief This function returns a reference to member index
 * @return Reference to member index
 */
uint32_t& DataPacket::index()
{
    return m_index;
}

/*!
 * @brief This function copies the value in member message
 * @param _message New value to be copied in member message
 */
void DataPacket::message(const std::string &_message)
{
m_message = _message;
}

/*!
 * @brief This function moves the value in member message
 * @param _message New value to be moved in member message
 */
void DataPacket::message(std::string &&_message)
{
m_message = std::move(_message);
}

/*!
 * @brief This function returns a constant reference to member message
 * @return Constant reference to member message
 */
const std::string& DataPacket::message() const
{
    return m_message;
}

/*!
 * @brief This function returns a reference to member message
 * @return Reference to member message
 */
std::string& DataPacket::message()
{
    return m_message;
}

/*!
 * @brief This function returns the maximum serialized size of the Key of an object
 * depending on the buffer alignment.
 * @param current_alignment Buffer alignment.
 * @return Maximum serialized size.
 */
size_t DataPacket::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;
    return current_align;
}

/*!
 * @brief This function tells you if the Key has been defined for this type
 */
bool DataPacket::isKeyDefined()
{
   return false;
}

/*!
 * @brief This function serializes the key members of an object using CDR serialization.
 * @param cdr CDR serialization object.
 */
void DataPacket::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
}
