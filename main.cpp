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

void test_setLoggingLevel()
{
  BOOST_LOG_FUNCTION();
  std::cout << "---- start test_setLoggingLevel ----" << std::endl;
  BOOST_LOG_SEV(app_logger::get(), logger::DEBUG) << "first debug";
  BOOST_LOG_SEV(app_logger::get(), logger::TRACE) << "first trace";

  std::cout << "set filter level \"DEBUG\"" << std::endl;
  logger::setLoggingLevel(logger::DEBUG);

  BOOST_LOG_SEV(app_logger::get(), logger::DEBUG) << "second debug"; // printed
  BOOST_LOG_SEV(app_logger::get(), logger::TRACE) << "second trace"; // filtered
  std::cout << "---- end test_setLoggingLevel ----" << std::endl;
}

int main(int argc, char *argv[])
{
  // initalize
  logger::initLogging();

  // set __LINE__ and __FUNCTION__
  BOOST_LOG_FUNCTION();

  test_logging();
  test_logging2();
  
  test_setLoggingLevel();

  std::cout << "---- end ----" << std::endl;
  return 0;
}
