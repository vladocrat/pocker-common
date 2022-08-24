#ifndef PROTOCOL_H
#define PROTOCOL_H

namespace Protocol
{
// CL side commands
namespace Client
{
static const int CL_HELLO = 0;
static const int CL_LOGIN = 2;
static const int CL_REGISTER = 4;
static const int CL_BET = 6;
static const int CL_FOLD = 8;
static const int CL_RAISE = 10;
static const int CL_ALLIN = 12;
static const int CL_CALL = 14;
static const int CL_CHECK = 16;
static const int CL_ROOM_CHOICE = 18;
static const int CL_LEAVE_ROOM = 20;
static const int CL_CREATE_ROOM = 22;
static const int CL_REQUEST_ROOMS = 24;
}; // Client

// SV side commands
namespace Server
{
static const int SV_HELLO = 1;
static const int SV_LOGIN = 3;
static const int SV_BET = 5;
static const int SV_FOLD = 7;
static const int SV_RAISE = 9;
static const int SV_ALLIN = 11;
static const int SV_CALL = 13;
static const int SV_CHECK = 15;
static const int SV_ROOM_CHOICE = 17;
static const int SV_REGISTER = 19;
static const int SV_LEFT_SUCCESSFULLY = 21;
static const int SV_JOINED_SUCCESSFULLY = 23;
static const int SV_ROOM_UPDATED = 25;
static const int SV_ROOM_CREATED = 27;
static const int SV_LIST_OF_ROOMS = 29;
}; // Server

// error handling
namespace Errors
{
static const int SV_LOGIN_ERR = 100;
static const int SV_REGISTRATION_ERR = 101;
static const int SV_ALREADY_LOGED_ERR = 102;
static const int SV_FAILED_TO_CREATE_ROOM = 103;
static const int SV_INTERNAL_SERVER_ERR = 500;
}; // ERRORS
}

#endif // PROTOCOL_H
