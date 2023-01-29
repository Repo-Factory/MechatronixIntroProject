#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>
#include <vector>

using namespace std::chrono_literals;

void printHumanTime(std::vector<long> UnixEpochTIme) {
  printf("The Date Is: %ld/%ld/%ld and the time is %ld:%ld", year, month, day, hour, minute); 
}

vector<long> convert(long UnixEpochTIme) { 
    long year = 1970 + (UnixEpochTime / 31536000);
    long month = 1 + ((UnixEpochTime / 2628288) % 12);
    long day = 1 + ((UnixEpochTime / 86400) % 30);
    long hour = 0 + ((UnixEpochTime / 3600) % 24 );
    long minute = 0 + ((UnixEpochTime / 60) % 60 );
    return vector<long> HumanTime = {year, month, day, hour, minute};
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc != 3) {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: convert time from Unix Epoch Time to Human Readable Time");
      return 1;
  }

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("convert_time_client");
  rclcpp::Client::SharedPtr client =
    node->create_client("convert_time");

  auto request = std::make_shared<Request>();
  request->HumanTime = atoll(argv[1]);
  

  while (!client->wait_for_service(5s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "The Date Is: %ld/%ld/%ld and the time is %ld:%ld", result.get()->HumanTime[0], result.get()->HumanTime[1], result.get()->HumanTime[2], result.get()->HumanTime[3], result.get()->HumanTime[4]);
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service add_two_ints");
  }

  rclcpp::shutdown();
  return 0;
}