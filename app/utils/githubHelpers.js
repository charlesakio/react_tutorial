var axios = require('axios')

var id = 'YOUR_CLIENT_ID';
var sec = 'YOUR_CLIENT_ID';
var param = '?client_id=' + id + '&client_secret=' + sec;

function getUserInfo(username) {
    //Fetch some data from github 
    return axios.get('https://api.github.com/users/' + username + param)
}

var helpers = {
  getPlayersInfo: function(players) {
    return axios.all(players.map (function (username) {
      return getUserInfo(username)
    })). then(function (info) {
        return info.map(function (user) {
          return user.data;
        })
    }).catch(function (err) {
      console.log('Error in getPlayersInfo', err);
    })
  }
};

module.exports = helpers;
