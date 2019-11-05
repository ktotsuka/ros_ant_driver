#ifndef ANT_ROS_DRIVER_H
#define ANT_ROS_DRIVER_H

#include <iostream>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include "ros/ros.h"
#include "ros/package.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int8.h"
#include "sensor_msgs/JointState.h"
#include <boost/shared_ptr.hpp>
#include <std_msgs/Bool.h>
#include "odva_ethernetip/session.h"
#include "odva_ethernetip/socket/socket.h"
#include "odva_ethernetip/serialization/serializable_buffer.h"
#include "odva_ethernetip/cpf_packet.h"
#include "odva_ethernetip/cpf_item.h"
#include "odva_ethernetip/sequenced_address_item.h"
#include "odva_ethernetip/sequenced_data_item.h"
#include "odva_ethernetip/socket/tcp_socket.h"
#include "odva_ethernetip/socket/udp_socket.h"

using namespace std;
using eip::socket::TCPSocket;
using eip::socket::UDPSocket;
using std::vector;
using eip::Session;
using eip::socket::Socket;
using std::cout;
using std::endl;
using boost::shared_ptr;
using boost::make_shared;
using boost::asio::buffer;
using eip::Session;
using eip::serialization::SerializableBuffer;
using eip::RRDataResponse;
using eip::CPFItem;
using eip::CPFPacket;
using eip::SequencedAddressItem;
using eip::SequencedDataItem;

class antRosDriver : public Session
{
public:
  antRosDriver(shared_ptr<Socket> socket, shared_ptr<Socket> io_socket)
    : Session(socket, io_socket), connection_num_(-1), mrc_sequence_num_(1)
  {
  }

  void startUDPIO();
  void sendUdp();


protected:
  ros::NodeHandle nh_;
  string host_;


private:
  int connection_num_;
  EIP_UDINT mrc_sequence_num_;

};

#endif
