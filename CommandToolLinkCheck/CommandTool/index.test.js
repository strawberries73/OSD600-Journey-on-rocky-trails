const nock = require("nock");
const { processLinks } = require("./index.js");

test("Pass file with invalid links 2", async () => {
    const result = await processLinks("./invalidLinks.txt");
    expect(result).toBe(false);
});