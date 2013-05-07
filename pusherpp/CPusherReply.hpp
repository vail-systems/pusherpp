#ifndef CPUSHERREPLY_H
#define	CPUSHERREPLY_H

#include <string>
#include <iostream>

namespace Pusherpp
{
	/**
	 * \brief Encapsulates a Pusher reply in terms of reply message and error code.
	 */
	class CPusherReply
	{
	public:
		/**
		 * \brief Enumerating all possible error codes generated by Pusher. Check http://pusher.com/docs/rest_api for
		 * more details.
		 */
		enum ErrorCode
		{
			PSH_SUCCESS       = 200, //!< Successful request. Body will contain a JSON hash of response data
			PSH_GENERIC_ERROR = 400, //!< Error: details in response body
			PSH_AUTH_ERROR    = 401, //!< Authentication error: response body will contain an explanation
			PSH_FORBIDDEN     = 403, //!< Forbidden: app disabled or over message quota
			PSH_OVERFLOW      = 413, //!< Event data size is > 10KB (The maximum allowed)
			PSH_UNKNOWN       = -1,  //!< Some undocumented error code was reported
		};
		
		CPusherReply();
		
		/**
		 * \brief COnstructs a CPusherReply with the provided parameters
		 * 
       * \param msg The message received from Pusher
       * \param err The error code received from Pusher
       */
		CPusherReply(const std::string& msg, ErrorCode err);
	
		~CPusherReply();
		
		std::string message; //!< The message received from Pusher
		ErrorCode   error;   //!< The error code reported by pusher
	};
	
	/**
		 * \brief Enables you to output the reply using any standard output stream, sweet for debugging
		 * 
       * \param os The output stream
       * \param rep The reply received from Pusher
       * \return A reference to the provided output stream
       */
		std::ostream& operator << (std::ostream& os, const CPusherReply& rep);
}

#endif /* CPUSHERREPLY_H */