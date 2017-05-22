import serial, time
import tweepy
import json

# set up the serial port ready to commuicate to the arduino
SPEED = 9600
PORT = '/dev/cu.usbmodem1411' # you may need to change this for your system
# check in the arduino IDE: TOOLS: PORT: to see what address your arduino is at.
ser = serial.Serial(PORT, SPEED, timeout=0, stopbits=serial.STOPBITS_TWO)

# Consumer keys and access tokens, used for OAuth
consumer_key = 'Ew03TN2R3kDuvRlrRjL3xldTI'
consumer_secret = 'ZthduTAFrO8GF6d7iNLWEVOOvxawqhPhSxBtLHbnUokzRU7K5w'

access_token = '866596052006293504-dDtTLPmRgOseKMllEiWHsCAZwu8y3hU'
access_token_secret = '8JH45gln36bICfM2FOHo9nxJmrvb1H2LybZl1d3bS163Q'

# OAuth process, using the keys and tokens
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)

class StdOutListener(tweepy.StreamListener):
    def on_data(self, data):
        # Twitter returns data in JSON format - we need to decode it first
        decoded = json.loads(data)
        # Also, we convert UTF-8 to ASCII ignoring all bad characters sent by users
        print '@%s: %s' % (decoded['user']['screen_name'], decoded['text'].encode('ascii', 'ignore'))
        ser.write("1")
        print ''
        return True

    def on_error(self, status):
        print status

if __name__ == '__main__':
    # http://stackoverflow.com/questions/419163/what-does-if-name-main-do
    l = StdOutListener()
    print "Showing all new tweets for #coventry:"
    # There are different kinds of streams: public stream, user stream, multi-user streams
        # In this example follow #programming tag   
    # For more details refer to https://dev.twitter.com/docs/streaming-apis
    stream = tweepy.Stream(auth, l)
    stream.filter(track=['coventry'])
