+++
title = "video-streaming-protocols"
+++

# Video Streaming Protocols

## HTTP Live Streaming (HLS)

## Dynamic Adaptive Streaming over HTTP (DASH)

Dynamic Adaptive Streaming over HTTP (DASH) is a protocol for streaming media
content over the internet using HTTP, where the server provides multiple
versions of the media content at different quality levels, and the client can
dynamically switch between these versions according to the client's current
network conditions. DASH is also known as MPEG-DASH.

DASH works by breaking the media content into small segments and having a
manifest file that describes the available segments and their quality levels.
The client will then request the appropriate segments based on the current
network conditions.

Since DASH is simply HTTP with a manifest file, setting up a DASH server can be
done by just using a standard web server to serve the media segments and the
manifest file. The manifest file (`.mpd`) is an XML file
(`applicatoin/dash+xml`) that points to the video segments, and this can be
generated using tools like FFmpeg.

Using cloud object storage services works the same way as using a web server. If
signed URLs should be used, the standard way of dealing with this is to use a
feature where the CDN's signed cookie can authorize access to entire directories
instead of single files, so that the manifest file and all the segments can be
accessed with a single signed cookie.

## WebRTC
