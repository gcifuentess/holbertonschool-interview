#!/usr/bin/node
// prints all characters of a Star Wars movie
const request = require('request');
const film = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + film + '/';
let data;
const idsList = [];
const characters = {};
request(url, function (error, response, body) {
  if (error) console.error('error:', error); // Print the error if one occurred
  data = JSON.parse(body);
  data.characters.forEach(element => {
    request(element, function (error1, response1, body1) {
      if (error) console.error('error:', error1); // Print the error if one occurred
      updateList(element, JSON.parse(body1).name);
    });
  });
});

function updateList (url, character) {
  idsList.push(extractId(url)); // stores the ids
  idsList.sort((a, b) => (a > b) ? 1 : -1); // sort the ids
  characters[extractId(url)] = character; // populates the dict to be printed
  const dictLen = Object.keys(characters).length; // len of the dict to be printed
  const charactersLen = data.characters.length; // len of the ogininal set of characters
  if (dictLen === charactersLen) {
    for (const id of idsList) {
      console.log(characters[id]);
    }
  }
}

function extractId (url) {
  url = url.slice(-4); // -4 to take last four chars of the url where is de id
  url = url.slice(url.search('/') + 1, 4); // to eliminate the "/"
  return (parseInt(url));
}
