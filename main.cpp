/* -8- ***********************************************************************
 *
 *  main.cpp
 *
 *                                          Created by ogata on 11/26/2013
 *                 Copyright (c) 2013 ABEJA Inc. All rights reserved.
 * ******************************************************************** -8- */

#include "logger.hpp"

void test_logging()
{
  boost::log::sources::severity_logger< logger::severity_level > slg;
  BOOST_LOG_FUNCTION();
  BOOST_LOG_SEV(slg, logger::ERROR) << "test";
}

void test_logging2()
{
  boost::log::sources::severity_logger< logger::severity_level > slg;
  BOOST_LOG_SEV(slg, logger::ERROR) << "test2";
}

int main(int argc, char *argv[])
{
  // initalize
  logger::initLogging();

  // set __LINE__ and __FUNCTION__
  BOOST_LOG_FUNCTION();
  
  BOOST_LOG_SEV(app_logger::get(), logger::WARNING) << "hello warn";

  test_logging();
  test_logging2();

  BOOST_LOG_SEV(app_logger::get(), logger::DEBUG) << "hello debug";

  return 0;
}
