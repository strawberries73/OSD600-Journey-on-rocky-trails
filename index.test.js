const nock = require("nock");
const { processLinks } = require("./index.js");

test("Pass file with valid links", async () => {
  const result = await processLinks("./validLinks.txt");
  expect(result).toEqual(true);
});
