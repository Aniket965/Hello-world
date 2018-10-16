const express = require('express')
const expressGraphql = require('express-graphql')
const app = express()
const { makeExecutableSchema } = require('graphql-tools')

const typeDefs = `
  type Query {
    helloWorld: String
  }
`

const resolvers = {
  Query: {
    helloWorld: () => {
      return 'Hello World!'
    }
  }
}

const schema = makeExecutableSchema({
  typeDefs,
  resolvers
})

app.use('/', expressGraphql({
  schema,
  graphiql: false
}))

app.listen(8080, () => {
  console.log('\nListening on http://localhost:8080')
})
