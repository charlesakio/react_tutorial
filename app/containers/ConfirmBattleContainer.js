var React = require('react');

var ConfirmBattle = require('../components/ConfirmBattle');
var githubHelpers = require('../utils/githubHelpers');

var ConfirmBattleContainer = React.createClass({
  contexTypes: {
    router: React.PropTypes.object.isRequired
  },
  getInitialState: function() {
    console.log('getInitialState')
    return {
      isLoading: true,
      playersInfo: [],
    }
  },
  componentDidMount: function() {
    var query = this.props.location.query;
    // https://egghead.io/playlists/the-this-key-word-250c37d9
    // For understanding .bind(this)
    githubHelpers.getPlayersInfo([query.playerOne, query.playerTwo])
    .then(function (players) {
      this.setState({
        isLoading: false,
        playersInfo: [players[0], players[1]]
      })
    }.bind(this))
  },
  componentWillMount: function() {
    console.log('componentWillMount')
    //Fetch infofrom github then update state
  },
  componentWillReceiveProps: function() {
    console.log('componentWillReceiveProps')
  },
  componentWillUnmount: function() {
    console.log('componentWillUnmount')
  },
  render: function() {
    return (
      <ConfirmBattle 
        isLoading={this.state.isLoading} 
        playersInfo={this.state.playersInfo} />
    )
  }
});

module.exports = ConfirmBattleContainer;


