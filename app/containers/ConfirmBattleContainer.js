var React = require('react');

var ConfirmBattle = require('../components/ConfirmBattle');

var ConfirmBattleContainer = React.createClass({
  contexTypes: {
    router: React.PropTypes.object.isRequired
  },
  getInitialState: function() {
    console.log('getInitialState')
    return {
      isLoading: true,
      playerInfo: []
    }
  },
  componentWillMount: function() {
    console.log('componentWillMount')
    //Fetch infofrom github then update state
  },
  componentDidMount: function() {
    var query = this.props.location.query;
    //Fetch info from github then update state
    console.log('componentDidMount')
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
        playerInfo={this.state.playerInfo}
        />

    );
  }
});

module.exports = ConfirmBattleContainer;


