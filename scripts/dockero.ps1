$env:CID="$(docker run --detach --rm -t --entrypoint bash luisferreira32/crunner)"
docker cp . ${env:CID}:/home/runner/
docker exec ${env:CID} bash -c 'make compile build valrun RUNNER_ARGS="--ch anagram1 --sv solver1"'
docker stop ${env:CID}
