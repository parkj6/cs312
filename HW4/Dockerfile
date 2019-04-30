## Simple NodeJS Hello World server
FROM alpine:latest
MAINTAINER Jong Park <parkj6@oregonstate.edu>

# During Build: Install the NodeJS runtime by running this command in the image
RUN apk -U add nodejs

# During build: Copy the server JS file into the image, store it at this location
COPY server.js /srv/server.js
COPY Dockerfile

# Expose the port 8080 for HTTP
EXPOSE 8080

# Run this command by default when containers spawned from this image start
CMD node /srv/server.js
