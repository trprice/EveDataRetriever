// EveDataRetriever.cpp : Defines the entry point for the application.
//

#include "EveDataRetriever.h"


// From the Http Client Tutorial located at:
//		https://github.com/microsoft/cpprestsdk/wiki/Getting-Started-Tutorial
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

int main()
{
	auto fileStream = std::make_shared<ostream>();

	// Open stream to output file.
	pplx::task<void> requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile)
		{
			*fileStream = outFile;

			// Create http_client to send the request.
			http_client client(U("http://www.bing.com/"));

			// Build request URI and start the request.
			uri_builder builder(U("/search"));
			builder.append_query(U("q"), U("cpprestsdk github"));
			return client.request(methods::GET, builder.to_string());
		})

	// Handle response headers arriving.
	.then([=](http_response response)
		{
			printf("Received response status code:%u\n", response.status_code());
		})

	// Close the file stream.
	.then([=](size_t)
		{
			return fileStream->close();
		});

	// Wait for all the outstanding I/O to complete and handle any exceptions
	try
	{
		requestTask.wait();
	}
	catch (const std::exception& e)
	{
		printf("Error exception:%s\n", e.what());
	}

	return 0;
}
