import serial, time
import tweepy
import json

# set up the serial port ready to commuicate to the arduino
SPEED = 9600
PORT = '/dev/cu.usbmodem1421' # you may need to change this for your system
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
        # ser.write("1")
        print ''
        if "forward" in decoded["text"]:
            ser.write("1")
            print 'forward'
        elif "backward" in decoded["text"]:
            ser.write("2")
            print 'backward'
        elif "left" in decoded["text"]:
            ser.write("3")
            print 'left'
        elif "write" in decoded["text"]:
            ser.write("4")
            print 'right'
        else:
            print 'No command recieved'
        print ''
        return True

    def on_error(self, status):
        print status

if __name__ == '__main__':
    try:
        # http://stackoverflow.com/questions/419163/what-does-if-name-main-do
        l = StdOutListener()
        print "Showing all new tweets for #104MCtest:"
        # There are different kinds of streams: public stream, user stream, multi-user streams
        # In this example follow #programming tag
        # For more details refer to https://dev.twitter.com/docs/streaming-apis
        stream = tweepy.Stream(auth, l, timeout=60)
        stream.filter(track=['104MCtest'])
    except KeyboardInterrupt:
        sys.exit()
    except AttributeError as e:
        print('AttributeError was returned, stupid bug')
        pass
    except tweepy.TweepError as e:
        print('Below is the printed exception')
        print(e)
        if '401' in e:
            # not sure if this will even work
            print('Below is the response that came in')
            print(e)
            sleep(60)
            pass
        else:
            #raise an exception if another status code was returned, we don't like other kinds
            raise e
    except Exception as e:
        print "Error. Restarting Stream.... Error: "
        print e.__doc__
        print e.message
