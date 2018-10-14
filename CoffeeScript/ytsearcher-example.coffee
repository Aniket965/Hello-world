{ YTSearcher } = require 'ytsearcher'
search = new YTSearcher '[Redacted YouTube API Key]'

search.search 'oHg5SJYRHA0', type: 'video'
  .then (searchResult) ->
    result = searchResult.first
    console.log result
    console.log "You just got #{result.title}"
    process.exit 0
  .catch console.error
