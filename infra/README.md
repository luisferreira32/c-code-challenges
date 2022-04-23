# Docker stuff up
This images hosted in a public registry and serve a couple functionalities in this repo, namely:
- compile, build, run
- github actions runner

# Locally
You can do something like:
```bash
docker run --rm -i -t --entrypoint bash luisferreira32/crunner
```
And then in another shell just copy stuff inside the image to test them (keep on the container while you develop):
```bash
docker ps # get the container id
docker cp . <container-id>:/home/runner/
```

Or just use the hacky dockero scripts we have around.
