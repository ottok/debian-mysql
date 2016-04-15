/*
 * Copyright (c) 2015, 2016, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */


#ifndef _XPL_DISPATCHER_H_
#define _XPL_DISPATCHER_H_

#include "mysqlx_connection.pb.h"
#include "mysqlx_sql.pb.h"
#include "mysqlx_crud.pb.h"

#include "ngs/protocol_encoder.h"

namespace xpl
{
  class Session;
  class Crud_command_handler;
  class Sql_data_context;
  class Expectation_stack;
  class Session_options;

  namespace dispatcher
  {
    bool dispatch_command(Session &session,
                          Sql_data_context &da,
                          ngs::Protocol_encoder &proto,
                          Crud_command_handler &crudh,
                          Expectation_stack &expect,
                          Session_options &options,
                          ngs::Request &command);
  };

  ngs::Error_code show_warnings_and_send(Sql_data_context &da, ngs::Protocol_encoder &proto);
}

#endif
