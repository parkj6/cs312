var http = require('http');
http.createServer(function (request, response)
{
	response.writeHead(200, {'Content-Type': 'text/plain'});
	response.end('Dockerfile');

}).listen(8080);
console.log('Server started');


