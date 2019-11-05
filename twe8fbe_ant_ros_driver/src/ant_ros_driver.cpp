#include "ant_ros_driver.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_bluebotics_driver");
  ros::NodeHandle nh;

  ROS_INFO("ros_bluebotics_driver started");

  // Get config params
  string host, local_ip;
  ros::param::param<std::string>("~host", host, "192.168.0.255");
  ros::param::param<std::string>("~local_ip", local_ip, "0.0.0.0");

  boost::asio::io_service io_service;
  shared_ptr<TCPSocket> socket = shared_ptr<TCPSocket>(new TCPSocket(io_service));
  shared_ptr<UDPSocket> io_socket = shared_ptr<UDPSocket>(new UDPSocket(io_service, 2222, local_ip));
  antRosDriver ant_ros_driver(socket, io_socket);

  ROS_INFO("Trying to open connection. host = %s, local_ip = %s", host.c_str(), local_ip.c_str());

  try
  {
    ant_ros_driver.open(host);
  }
  catch (std::runtime_error ex)
  {
    ROS_FATAL_STREAM("Exception caught opening session: " << ex.what());
    return -1;
  }

  ROS_INFO("Trying to start UDP IO");

  try
  {
    ant_ros_driver.startUDPIO();
    ant_ros_driver.sendUdp();
  }
  catch (std::logic_error ex)
  {
    ROS_FATAL_STREAM("Could not start UDP IO: " << ex.what());
    return -1;
  }








  ros::spin();

  return 0;
}

void antRosDriver::startUDPIO()
{
  EIP_CONNECTION_INFO_T o_to_t, t_to_o;
  o_to_t.assembly_id = 0x71;
  o_to_t.buffer_size = 0x006E;
  o_to_t.rpi = 0x00177FA0; // 100000?
  t_to_o.assembly_id = 0x66;
  t_to_o.buffer_size = 0x0584;
  t_to_o.rpi = 0x00013070; // 100000?

  connection_num_ = createConnection(o_to_t, t_to_o);
}

void antRosDriver::sendUdp()
{
//  CPFPacket pkt;
//  shared_ptr<SequencedAddressItem> address =
//    make_shared<SequencedAddressItem>(
//      getConnection(connection_num_).o_to_t_connection_id, mrc_sequence_num_++);
//  shared_ptr<MeasurementReportConfig> data = make_shared<MeasurementReportConfig>();
//  *data = mrc_;
//  pkt.getItems().push_back(CPFItem(0x8002, address));
//  pkt.getItems().push_back(CPFItem(0x00B1, data));
//  sendIOPacket(pkt);
}
