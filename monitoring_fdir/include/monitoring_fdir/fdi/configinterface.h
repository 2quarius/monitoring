/*
 * configinterface.h
 *
 *  Created on: Dec 6, 2017
 *      Author: matthias
 */

#ifndef SRC_FDIR_CONFIGINTERFACE_H_
#define SRC_FDIR_CONFIGINTERFACE_H_

#include "ros/ros.h"
#include "monitoring_msgs/KeyValue.h"
#include "monitoring_msgs/Error.h"



/**
 * @brief The ConfigInterface class is a Interface for the implementation of fdi validators. This allows to create classes that can be used with the fdiSDK.
 */
class ConfigInterface
{
public:
  ConfigInterface(ros::Publisher& publisher);
  virtual ~ConfigInterface();

  /**
   * @brief check will be called by the fdiSDK to validate if the key-value pair is a error.
   * You need to check if this is so and publish an error with the function publishError
   * @param newMsg is the keyvalue that was registered for this validator
   */
  virtual void check(monitoring_msgs::KeyValue newMsg) = 0;

protected:
  ros::Publisher pub;
  /**
   * @brief publishError used to publish an occuring error
   * @param errormsg
   */
  void publishError(monitoring_msgs::Error errormsg);
  char hostname[30];
};

#endif /* SRC_FDIR_CONFIGINTERFACE_H_ */
