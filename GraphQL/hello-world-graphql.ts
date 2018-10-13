import { GraphQLServer } from 'graphql-yoga';

const typeDefs = `
  type Query {
    greet: String
  }
`

const resolvers = {
  Query: {
    greet: () => 'hello world'
  }
}

const server = new GraphQLServer({typeDefs, resolvers})
server.start(() => console.log('⚡️  Waiting to greet you at http://localhost:4000'))